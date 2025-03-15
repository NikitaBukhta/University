import unittest as ut
import origin_library as Library

class LibraryTestCase(ut.TestCase):
    def setUp(self):
        self.library = Library.Library()
        self.testBook = {"title": "test title", "author": "test author"}

        for i in range(100):
          self.library.add_book(self.testBook["title"] + str(i), self.testBook["author"] + str(i))

        return super().setUp()

    def tearDown(self):
        return super().tearDown()
    
    def test_addBook(self):
        prevCount = len(self.library.books)
        self.library.add_book(self.testBook["title"], self.testBook["author"])
        self.assertEqual(len(self.library.books), prevCount + 1)
        self.assertEqual(self.library.books[prevCount], self.testBook)

    def test_addManyBooks(self):
        prevCount = len(self.library.books)
        itCount = 100
        for _ in range(itCount):
            self.library.add_book(self.testBook["title"], self.testBook["author"])

        self.assertEqual(len(self.library.books), itCount + prevCount)
        for i in range(prevCount, itCount + prevCount):
          self.assertEqual(self.library.books[i], self.testBook)
    
    def test_removeFirstBook(self):
        prevCount = len(self.library.books)

        self.library.remove_book(self.testBook["title"] + str(0));
        self.assertEqual(len(self.library.books), prevCount - 1)

    def test_removeMidBook(self):
        prevCount = len(self.library.books)

        self.library.remove_book(self.testBook["title"] + str(int(prevCount / 2)));
        self.assertEqual(len(self.library.books), prevCount - 1)

    def test_removeLastBook(self):
        prevCount = len(self.library.books)

        self.library.remove_book(self.testBook["title"] + str(prevCount - 1))
        self.assertEqual(len(self.library.books), prevCount - 1)

    def test_removeSeveralBooks(self):
      prevCount = len(self.library.books)
      step = 5

      for i in range(0, prevCount, step):
          self.library.remove_book(self.testBook["title"] + str(i))

      self.assertEqual(len(self.library.books), prevCount - (prevCount / step))

    def test_findOneFirstBookByAuthor(self):
        testBook = {"title": self.testBook["title"] + str(0), "author": self.testBook["author"] + str(0)}
        foundBooks = self.library.find_books_by_author(testBook["author"])

        self.assertEqual(len(foundBooks), 1)
        self.assertEqual(foundBooks[0], testBook["title"])

    def test_findOneMiddleBookByAuthor(self):
        count = len(self.library.books)
        testBook = {"title": self.testBook["title"] + str(int(count / 2)), "author": self.testBook["author"] + str(int(count / 2))}
        foundBooks = self.library.find_books_by_author(testBook["author"])

        self.assertEqual(len(foundBooks), 1)
        self.assertEqual(foundBooks[0], testBook["title"])

    def test_findOneEndBookByAuthor(self):
        count = len(self.library.books)
        testBook = {"title": self.testBook["title"] + str(int(count - 1)), "author": self.testBook["author"] + str(int(count - 1))}
        foundBooks = self.library.find_books_by_author(testBook["author"])

        self.assertEqual(len(foundBooks), 1)
        self.assertEqual(foundBooks[0], testBook["title"])

    def test_findSeveralBooksByAuthor(self):
        itCount = 5
        count = len(self.library.books)
        for i in range(0, count, int(count / 5)):
            self.library.books[i] = self.testBook

        foundBooks = self.library.find_books_by_author(self.testBook["author"])
        self.assertEqual(len(foundBooks), itCount)
        for i in range(itCount):
            self.assertEqual(foundBooks[i], self.testBook["title"])

    def test_findOneFirstBookByTitle(self):
        testBook = {"title": self.testBook["title"] + str(0), "author": self.testBook["author"] + str(0)}
        foundBooks = self.library.find_books_by_title(testBook["title"])

        self.assertEqual(len(foundBooks), 1)
        self.assertEqual(foundBooks[0], testBook)

    def test_findOneMiddleBookByTitle(self):
        count = len(self.library.books)
        testBook = {"title": self.testBook["title"] + str(int(count / 2)), "author": self.testBook["author"] + str(int(count / 2))}
        foundBooks = self.library.find_books_by_title(testBook["title"])

        self.assertEqual(len(foundBooks), 1)
        self.assertEqual(foundBooks[0], testBook)

    def test_findOneEndBookByTitle(self):
        count = len(self.library.books)
        testBook = {"title": self.testBook["title"] + str(int(count - 1)), "author": self.testBook["author"] + str(int(count - 1))}
        foundBooks = self.library.find_books_by_title(testBook["title"])

        self.assertEqual(len(foundBooks), 1)
        self.assertEqual(foundBooks[0], testBook)

    def test_findSeveralBooksByTitle(self):
        itCount = 5
        count = len(self.library.books)
        testBook = {"title": self.testBook["title"] + str(int(count)), "author": self.testBook["author"] + str(int(count))}
        for i in range(0, count, int(count / 5)):
            self.library.books[i] = testBook

        foundBooks = self.library.find_books_by_title(testBook["title"])
        self.assertEqual(len(foundBooks), itCount)
        for i in range(itCount):
            self.assertEqual(foundBooks[i], testBook)

    def test_findSeveralBooksWithSimilarTitle(self):
        count = len(self.library.books)

        foundBooks = self.library.find_books_by_title(self.testBook["title"])
        self.assertEqual(len(foundBooks), count)
        for i in range(count):
            self.assertTrue(self.testBook["title"] in foundBooks[i]["title"])


if __name__ == '__main__':
    ut.main()
