/* ex: set tabstop=8 expandtab: */
/*
  Copyright (c) 2006 - 2018
  CLST  - Radboud University
  ILK   - Tilburg University

  This file is part of frog:

  A Tagger-Lemmatizer-Morphological-Analyzer-Dependency-Parser for
  several languages

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
      https://github.com/LanguageMachines/frog/issues
  or send mail to:
      lamasoftware (at ) science.ru.nl

*/

#ifndef FROGDATA_H
#define FROGDATA_H

#include <string>
#include <vector>

class frog_data {
 public:
 frog_data():no_space(false),tag_confidence(0.0){};
  std::string word;
  std::string token_class;
  bool no_space;
  std::string tag;
  double tag_confidence;
  std::vector<std::string> lemmas;
  std::vector<std::string> morphs;
  std::vector<std::string> morphs_nested;
};

std::ostream& operator<<( std::ostream&, const frog_data& );

#endif
