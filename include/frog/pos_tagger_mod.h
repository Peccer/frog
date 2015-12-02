/*
  $Id: cgn_tagger_mod.h 18128 2015-03-02 16:11:55Z sloot $
  $URL: https://ilk.uvt.nl/svn/sources/Frog/trunk/include/frog/cgn_tagger_mod.h $

  Copyright (c) 2006 - 2015
  Tilburg University

  This file is part of frog.

  frog is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  frog is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  For questions and suggestions, see:
      http://ilk.uvt.nl/software.html
  or send mail to:
      timbl@uvt.nl
*/

#ifndef POS_TAGGER_MOD_H
#define POS_TAGGER_MOD_H

#include "mbt/MbtAPI.h"

class POSTagger {
 public:
  POSTagger(TiCC::LogStream*);
  virtual ~POSTagger();
  virtual bool init( const TiCC::Configuration& );
  virtual void Classify( const std::vector<folia::Word *>& );
  void addDeclaration( folia::Document& ) const;
  void addTag( folia::Word *, const std::string&, double );
  std::vector<TagResult> tagLine( const std::string& );
  std::string getTagset() const { return tagset; };
  bool fill_map( const std::string&, std::map<std::string,std::string>& );
  std::string set_eos_mark( const std::string& );
 protected:
  int debug;
  std::string tagset;
  LogStream *tag_log;
 private:
  MbtAPI *tagger;
  std::string version;
  Tokenizer::UnicodeFilter *filter;
  std::map<std::string,std::string> token_tag_map;
  std::set<std::string> valid_tags;
};

#endif // POS_TAGGER_MOD_H