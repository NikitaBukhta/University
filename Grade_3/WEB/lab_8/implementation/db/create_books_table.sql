CREATE TABLE books (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    author VARCHAR(255) NOT NULL,
    genre VARCHAR(100),
    publication_year INT,
    isbn VARCHAR(20) UNIQUE
);

INSERT INTO books (title, author, genre, publication_year, isbn) VALUES
('To Kill a Mockingbird', 'Harper Lee', 'Novel', 1960, '9780061120084'),
('1984', 'George Orwell', 'Dystopian fiction', 1949, '9780451524935'),
('The Great Gatsby', 'F. Scott Fitzgerald', 'Novel', 1925, '9780743273565'),
('Pride and Prejudice', 'Jane Austen', 'Novel', 1813, '9780141439518'),
('The Catcher in the Rye', 'J.D. Salinger', 'Novel', 1951, '9780316769488');
