# 0x20-regex
This interview algorithm project utilizes regular expressions (RegEx)

[Simple RegEx](/0x20-regex/regex.c)
* Write a function in C `int regex_match(char const *str, char const *pattern)` that checks whether a given pattern matches a given string:
  * `str` is the string to scan
  * `pattern` is the regular expression
  * returns `1` if matches the string or `0` if doesn't
  * `str` can be empty or can contain any ASCII character except `.` or `*`
  * `pattern` can be empty or can contain any ASCII character, including `.` and `*`
  * `.` matches with any single character
  * `*` matches zero or more of the preceding chatacter

### test_files
The [test_files](/0x20-regex/test_files/) directory contains files used to test the output of the algorithm locally.
