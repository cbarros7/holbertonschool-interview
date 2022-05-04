# 0x13. Count it!

### [0. Count it!](./0-count.py)

- Write a recursive function that queries the Reddit API, parses the title of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces. Javascript should count as javascript, but java should not).

- Prototype: `def count_words(subreddit, word_list)`
  - Note: You may change the prototype, but it must be able to be called with just a subreddit supplied and a list of keywords. AKA you can add a counter or anything else, but the function must work without supplying a starting value in the main.
  - Results should be printed in descending order, by the count, and if the count is the same for separate keywords, they should then be sorted alphabetically. Words with no matches should be skipped and not printed.
  - Results are based on the number of times a keyword appears, not titles it appears in. ‘java java java’ counts as 3 separate occurrences of java.
  - To make life easier, ‘java.’ or ‘java!’ or ‘java\_’ should not count as ‘java’
  - If no posts match or the subreddit is invalid, print a newline.
  - NOTE: Invalid subreddits may return a redirect to search results. Ensure that you are NOT following redirects.

```
wintermancer@lapbox ~/reddit_api/project $ cat 100-main.py
```

```python
#!/usr/bin/python3
import sys

if __name__ == '__main__':
    count_words = __import__('100-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
```

```
wintermancer@lapbox ~/reddit_api/project $ python3 100-main.py programming 'python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
scala: 4
wintermancer@lapbox ~/reddit_api/project $ python3 100-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
wintermancer@lapbox ~/reddit_api/project $ python3 100-main.py not_a_valid_subreddit 'python java'
```