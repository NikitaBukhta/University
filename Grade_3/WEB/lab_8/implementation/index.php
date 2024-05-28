<?php
// Підключення до бази даних SQLite
$db = new SQLite3('db/bookstore.db');

// Пошук книги
if (isset($_GET['search_title'])) {
    $search_title = $_GET['search_title'];
    $query = "SELECT * FROM books WHERE title LIKE '%$search_title%'";
    $result = $db->query($query);

    // Вивід результатів пошуку
    echo "<h2>Результати пошуку:</h2>";
    if ($result) {
        while ($row = $result->fetchArray()) {
            echo "Назва: " . $row['title'] . "<br>";
            echo "Автор: " . $row['author'] . "<br>";
            echo "Жанр: " . $row['genre'] . "<br>";
            echo "Рік публікації: " . $row['publication_year'] . "<br>";
            echo "ISBN: " . $row['isbn'] . "<br><br>";
        }
    } else {
        echo "Книги за вказаною назвою не знайдено.";
    }
}

// Додавання книги
if (isset($_POST['add_book'])) {
    $title = $_POST['title'];
    $author = $_POST['author'];
    $genre = $_POST['genre'];
    $publication_year = $_POST['publication_year'];
    $isbn = $_POST['isbn'];
    $current_year = date("Y");

    if ($publication_year >= 0 && $publication_year <= $current_year) {
        $query = "INSERT INTO books (title, author, genre, publication_year, isbn) VALUES ('$title', '$author', '$genre', $publication_year, '$isbn')";
        $db->exec($query);
        echo "Книга успішно додана.";
    } else {
        echo "Некоретний рік випуску книги";
    }
}

// Видалення книги
if (isset($_POST['delete_id'])) {
    $delete_id = $_POST['delete_id'];
    $query = "DELETE FROM books WHERE isbn = $delete_id";
    $db->exec($query);
    echo "Книга успішно видалена.";
}
?>
<!DOCTYPE html>
<html lang="uk">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Управління книгами</title>
</head>
<body>
    <h1>Управління книгами</h1>

    <h2>Пошук книги</h2>
    <form action="" method="GET">
        <label for="search_title">Назва книги:</label>
        <input type="text" id="search_title" name="search_title">
        <button type="submit">Знайти</button>
    </form>

    <h2>Додати книгу</h2>
    <form action="" method="POST">
        <label for="title">Назва:</label>
        <input type="text" id="title" name="title" required><br>
        <label for="author">Автор:</label>
        <input type="text" id="author" name="author" required><br>
        <label for="genre">Жанр:</label>
        <input type="text" id="genre" name="genre"><br>
        <label for="publication_year">Рік публікації:</label>
        <input type="number" id="publication_year" name="publication_year"><br>
        <label for="isbn">ISBN:</label>
        <input type="text" id="isbn" name="isbn"><br>
        <button type="submit" name="add_book">Додати книгу</button>
    </form>

    <h2>Видалити книгу</h2>
    <form action="" method="POST">
        <label for="delete_id">ISBN книги:</label>
        <input type="number" id="delete_id" name="delete_id" required><br>
        <button type="submit">Видалити книгу</button>
    </form>
</body>
</html>
