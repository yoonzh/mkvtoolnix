/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   class definitions for the VC1 ES demultiplexer module

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __R_VC1_H
#define __R_VC1_H

#include "common/common_pch.h"

#include "merge/pr_generic.h"
#include "common/vc1.h"

class vc1_es_reader_c: public generic_reader_c {
private:
  memory_cptr m_raw_seqhdr;

  memory_cptr m_buffer;

  vc1::sequence_header_t m_seqhdr;

public:
  vc1_es_reader_c(const track_info_c &ti, const mm_io_cptr &in);

  virtual const std::string get_format_name(bool translate = true) const {
    return translate ? Y("VC1") : "VC1";
  }

  virtual void read_headers();
  virtual file_status_e read(generic_packetizer_c *ptzr, bool force = false);
  virtual void identify();
  virtual void create_packetizer(int64_t id);

  static int probe_file(mm_io_c *in, uint64_t size);
};

#endif // __R_VC1_H
