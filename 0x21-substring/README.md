# 0x21-substring
This interview algorithm project finds all the possible substrings containing a list of words, within a given string.

[Substring with Concatenated Words](/0x21-substring/substring.c)
* Write a function in C `int *find_substring(char const *s, char const **words, int nb_words, int *n)` that finds all possible substrings containing a list of words within a given string:
  * `s` is the string to scan
  * `words` is the array of words all substrings must be a concatenation arrangement of
  * `nb_words` is the number of elements in the array `words`
  * `n` holds the address at which to store the number of elements in the returned array
  * returns an allocated array, storing each index in `s`, at which a substring was found or `NULL` if no solution is found
  * all words in the array `words` are the same length
  * a valid substring `s` is the concatenation of each word in `words` exactly once and without any intervening characters

### test_files
The [test_files](/0x21-substring/test_files/) directory contains files used to test the output of the algorithm locally.
