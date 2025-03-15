# library.py

class Library:
    def __init__(self):
        # Бібліотека зберігає книги як список словників
        self.books = []

    def add_book(self, title, author):
        """
        Додає книгу до бібліотеки.
        :param title: Назва книги
        :param author: Автор книги
        """
        self.books.append({"title": title, "author": author})

    def remove_book(self, title):
        """
        Видаляє книгу з бібліотеки за її назвою.
        :param title: Назва книги для видалення
        """
        for book in self.books:
            if book["title"] == title:
                self.books.remove(book)
                return
        # Помилка: метод нічого не робить, якщо книгу не знайдено.
        # ---- Яка помилка у цьому методі? Що має робити метод з видалення книжки, окрім видалення?

    def find_books_by_author(self, author):
        """
        Знаходить усі книги, написані певним автором.
        :param author: Ім'я автора
        :return: Список назв книг, написаних автором
        """
        ret = []
        # Помилка: повертає лише першу знайдену книгу, а не всі книги автора
        # Fixed
        for book in self.books:
            if book["author"] == author:
                ret.append(book["title"])

        return ret

    def find_books_by_title(self, title):
        """
        Знаходить книги, які містять вказану назву.
        :param title: Назва або частина назви книги
        :return: Список книг, назви яких містять вказаний текст
        """
        ret = []
        # Помилка: порівняння відбувається тільки за точним збігом
        # Fixed
        for book in self.books:
            if title.lower() in book["title"].lower():
                ret.append(book)
                
        return ret