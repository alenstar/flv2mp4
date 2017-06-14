#include <xlog.h>

#include "media_sink.h"
#include "raw_parser.h"

namespace flv{

MediaSink::MediaSink(const std::string &flvpath) :
  m_vparser(new VideoRawParser),
  m_aparser(new AudioRawParser)
{
  if (!flvpath.empty()) {
    if (m_flvmuxer.set_file(flvpath) < 0) {
      LOGE("flvmuxer's set_file() failed");
      // Fall through
    }
  }
}

MediaSink::~MediaSink()
{
  SAFE_DELETE(m_vparser);
  SAFE_DELETE(m_aparser);
}

}
