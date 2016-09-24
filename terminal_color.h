/* 
 * Copyright 2016 Waizung Taam
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstdarg>
#include <cstdio>

#define RESET     0
#define BRIGHT    1
#define DIM       2
#define UNDERLINE 4
#define BLINK     5
#define REVERSE   7
#define HIDDEN    8

#define BLACK     0
#define RED       1
#define GREEN     2
#define YELLOW    3
#define BLUE      4
#define MAGENTA   5
#define CYAN      6
#define WHITE     7

class TerminalColor {
public:
  TerminalColor() :
    attribute_(BRIGHT), foreground_color_(WHITE), background_color_(BLACK) {}
  TerminalColor(int attr, int fgc, int bgc) :
    attribute_(attr), foreground_color_(fgc), background_color_(bgc) {}
  
  void print() const {
    char control_code[13];
    sprintf(control_code, "%c[%d;%d;%dm", 0x1B, attribute_, 
            foreground_color_ + 30, background_color_ + 40);
    printf("%s", control_code);
  }

private:
  int attribute_;
  int foreground_color_;
  int background_color_;
};

void colored_print(const TerminalColor& color, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  color.print();
  printf("%s", fmt);
  TerminalColor().print();
  va_end(args);
}