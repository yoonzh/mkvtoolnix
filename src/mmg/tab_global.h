/*
  mkvmerge GUI -- utility for splicing together matroska files
      from component media subtypes

  tab_global.h

  Written by Moritz Bunkus <moritz@bunkus.org>
  Parts of this code were written by Florian Wager <root@sirelvis.de>

  Distributed under the GPL
  see the file COPYING for details
  or visit http://www.gnu.org/copyleft/gpl.html
*/

/*!
    \file
    \version $Id$
    \brief declarations for the global tab
    \author Moritz Bunkus <moritz@bunkus.org>
*/

#ifndef __TAB_GLOBAL_H
#define __TAB_GLOBAL_H

#define ID_B_BROWSEGLOBALTAGS             13000
#define ID_B_BROWSECHAPTERS               13001
#define ID_CB_SPLIT                       13002
#define ID_RB_SPLITBYSIZE                 13003
#define ID_RB_SPLITBYTIME                 13004
#define ID_CB_SPLITBYSIZE                 13005
#define ID_CB_SPLITBYTIME                 13006
#define ID_CB_LINK                        13007
#define ID_TC_SPLITMAXFILES               13008
#define ID_TC_PREVIOUSSEGMENTUID          13009
#define ID_TC_NEXTSEGMENTUID              13010
#define ID_TC_CHAPTERS                    13011
#define ID_CB_CHAPTERLANGUAGE             13012
#define ID_CB_CHAPTERCHARSET              13013
#define ID_TC_GLOBALTAGS                  13014
#define ID_TC_SEGMENTTITLE                13015
#define ID_TC_CUENAMEFORMAT               13016

class tab_global: public wxPanel {
  DECLARE_CLASS(tab_global);
  DECLARE_EVENT_TABLE();
public:
  wxTextCtrl *tc_chapters, *tc_global_tags, *tc_split_max_files, *tc_title;
  wxTextCtrl *tc_next_segment_uid, *tc_previous_segment_uid;
  wxTextCtrl *tc_split_bytes, *tc_split_time, *tc_cue_name_format;
  wxCheckBox *cb_split, *cb_link;
  wxRadioButton *rb_split_by_size, *rb_split_by_time;
  wxComboBox *cob_split_by_size, *cob_split_by_time;
  wxComboBox *cob_chap_language, *cob_chap_charset;

public:
  tab_global(wxWindow *parent);

  void on_browse_chapters(wxCommandEvent &evt);
  void on_browse_global_tags(wxCommandEvent &evt);
  void on_split_clicked(wxCommandEvent &evt);
  void on_splitby_clicked(wxCommandEvent &evt);

  void save(wxConfigBase *cfg);
  void load(wxConfigBase *cfg);
  bool validate_settings();
};

#endif // __TAB_GLOBAL_H
