from collections import defaultdict


class TrieNode():

    def __init__(self):
        self.children = defaultdict()
        self.terminating = False


class Trie():

    def __init__(self):
        self.root = self.get_node()

    def get_node(self):
        return TrieNode()

    def get_index(self, ch):
        return ord(ch) - ord('a')

    def insert(self, word):

        root = self.root
        len_word = len(word)

        for i in range(len_word):
            index = self.get_index(word[i])

            if index not in root.children:
                root.children[index] = self.get_node()
            root = root.children.get(index)

        root.terminating = True

    def search(self, word):
        root = self.root
        len_word = len(word)

        for i in range(len_word):
            index = self.get_index(word[i])
            if not root:
                return False
            root = root.children.get(index)

        return True if root and root.terminating else False

    def delete(self, word):

        root = self.root
        len_word = len(word)

        for i in range(len_word):
            index = self.get_index(word[i])

            if not root:
                print("Word not found")
                return -1
            root = root.children.get(index)

        if not root:
            print("Word not found")
            return -1
        else:
            root.terminating = False
            return 0

    def update(self, old_word, new_word):
        val = self.delete(old_word)
        if val == 0:
            self.insert(new_word)

    

if __name__ == "__main__":

    strings = ["abcd", "efgh", "ijkl", "mnop", "abcd"]

    t = Trie()
    for word in strings:
        t.insert(word)

    print(t.search("abcd"))
    print(t.search("efgh"))

    t.delete("efgh")

    print(t.search("efgh"))

    t.update("mnop", "efgh")