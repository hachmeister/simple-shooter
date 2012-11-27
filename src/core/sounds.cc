#include "core/sounds.h"

#include <iostream>
#include <stdexcept>

#include <vorbis/vorbisfile.h>

ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };
ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };
ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };
ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };
ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };

Sounds::Sounds()
  : device(0), context(0), channels(16)
{
  device = alcOpenDevice(NULL);
  context = alcCreateContext(device, NULL);
  alcMakeContextCurrent(context);
  
  alListenerfv(AL_POSITION,    ListenerPos);
  alListenerfv(AL_VELOCITY,    ListenerVel);
  alListenerfv(AL_ORIENTATION, ListenerOri);
  
  for (std::vector<ALuint>::iterator it = channels.begin(); it != channels.end(); ++it) {
    alGenSources(1, &(*it));
  }
}

Sounds::~Sounds()
{
  for (std::map<std::string, ALuint>::iterator it = sounds.begin(); it != sounds.end(); ++it) {
    alDeleteBuffers(1, &(it->second));
  }
  
  for (std::vector<ALuint>::iterator it = channels.begin(); it != channels.end(); ++it) {
    alDeleteSources(1, &(*it));
  }
  
  alcMakeContextCurrent(NULL);
  alcDestroyContext(context);
  alcCloseDevice(device);
}

void Sounds::playSound(const std::string& name)
{
  ALuint buffer = 0;
  ALuint source = 0;
  ALint state;
  
  buffer = loadSound(name);
  if (buffer == 0) {
    return;
  }
  
  for (std::vector<ALuint>::iterator it = channels.begin(); it != channels.end(); ++it) {
    alGetSourcei(*it, AL_SOURCE_STATE, &state);
    
    if (state != AL_PLAYING) {
      source = *it;
    }
  }
  
  if (source == 0) {
    return;
  }
  
  alSourceRewind(source);
  
  alSourcei (source, AL_BUFFER,   buffer   );
  alSourcef (source, AL_PITCH,    1.0f     );
  alSourcef (source, AL_GAIN,     1.0f     );
  alSourcefv(source, AL_POSITION, SourcePos);
  alSourcefv(source, AL_VELOCITY, SourceVel);
  alSourcei (source, AL_LOOPING,  AL_FALSE );

  if (alGetError() == AL_NO_ERROR) {
    alSourcePlay(source);
  }
}

void Sounds::playMusic(const std::string& name)
{
}

ALuint Sounds::loadSound(const std::string& name)
{
  if (sounds.count(name) > 0) {
    return sounds[name];
  }
  
  ALuint buffer;
  FILE* file;
  OggVorbis_File oggFile;
  vorbis_info* vorbisInfo;
  
  alGenBuffers(1, &buffer);
  if (alGetError() != AL_NO_ERROR) {
    return 0;
  }
  
  file = fopen(name.c_str(), "rb");
  if (!file) {
    alDeleteBuffers(1, &buffer);
    return 0;
  }
  
  int result = ov_open(file, &oggFile, NULL, 0);
  if(result < 0) {
    alDeleteBuffers(1, &buffer);
    fclose(file);
    return 0;
  }
  
  vorbisInfo = ov_info(&oggFile, -1);
  
  ALenum format;
  
  if (vorbisInfo->channels == 1) {
    format = AL_FORMAT_MONO16;
  }
  else {
    format = AL_FORMAT_STEREO16;
  }
  
  unsigned int dataSize = ov_pcm_total(&oggFile, -1) * vorbisInfo->channels * 2;
  
  int section;
  unsigned int size = 0;
  char* data = new char[dataSize];
  
  while (size < dataSize) {
    result = ov_read(&oggFile, data + size, dataSize - size, 0, 2, 1, &section);
    
    if (result > 0) {
      size += result;
    }
    else {
      break;
    }
  }
  
  if (size != dataSize) {
    alDeleteBuffers(1, &buffer);
    ov_clear(&oggFile);
    delete data;
    return 0;
  }
  
  alBufferData(buffer, format, data, dataSize, vorbisInfo->rate);
  
  delete data;
  ov_clear(&oggFile);
  
  sounds[name] = buffer;
  
  return buffer;
}
