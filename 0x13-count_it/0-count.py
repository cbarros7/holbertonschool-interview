#!/usr/bin/python3
"""
Write a recursive function that queries the Reddit API, parses the title of all
hot articles, and prints a sorted count of given keywords (case-insensitive,
delimited by spaces. Javascript should count as javascript,
but java should not).
"""
import json
import pprint
import requests
import sys

headers = {
    'User-Agent': 'My User Agent 1.0'
}
after = None


def recurse(subreddit, hot_list=[]):
    """function that returns a list with the titles of all hot articles"""
    try:
        url = 'https://www.reddit.com/r/'
        global after
        if after:
            response = requests.get(url + subreddit + "/hot.json?after=" +
                                    after, headers=headers,
                                    allow_redirects=False)
            # pprint.pprint(response.json())
        else:
            response = requests.get(url + subreddit + "/hot.json",
                                    headers=headers, allow_redirects=False)
            # pprint.pprint(response.json())
        after = response.json()['data']['after']
        hot_list += [element['data']['title'] for element in response.
                     json()['data']['children']]
        if after:
            return recurse(subreddit, hot_list)
        return hot_list
    except Exception:
        return None


def count_words(subreddit, word_list):
    """
    function that parses the title of all hot articles, and prints a sorted
    count of given keywords (case-insensitive, delimited by spaces.
    Javascript should count as javascript, but java should not)
    """

    # Make a call to recurse() to fetch all the titles
    hot_list = recurse(subreddit)
    # print(hot_list)
    if hot_list is None:
        return None

    # Initialize a dictionary of counters with the words of word_list as keys
    counts = {word: 0 for word in word_list}
    # print(counts)

    for title in hot_list:
        # Compose a list of lowercase words from the title string
        # (hence allowing for a count of several iterations of the same word
        # in the title, if any)
        title = title.lower().split()
        for word in word_list:
            for item in title:
                # Avoid substring search by comparing exact words
                # in two separate lists (using '==' for the validation)
                if word.lower() == item:
                    counts[word] += 1

    # Sort alphabetically first (based on keys):
    sort_by_alpha = sorted(counts.items(), key=lambda x: x[0])
    # print(sort_by_alpha)
    # Sort by count (ascending, based on values):
    sort_by_count = sorted(sort_by_alpha, key=lambda x: x[1], reverse=True)
    # print(sort_by_count)
    for key, value in sort_by_count:
        if value != 0:
            print(key + ": " + str(value))
