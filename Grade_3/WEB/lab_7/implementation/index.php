<!DOCTYPE html>
<html>
<head>
    <title>Форма заказа запчастей</title>
</head>
<body>

<?php
// Проверка, была ли отправлена форма
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Проверка и обработка данных формы
    $errors = array();

    // Проверка наличия заполненных полей
    if (empty($_POST["part_name"])) {
        $errors[] = "Название запчасти обязательно для заполнения.";
    }
    if (empty($_POST["quantity"]) || !is_numeric($_POST["quantity"]) || $_POST["quantity"] <= 0) {
        $errors[] = "Количество должно быть положительным числом.";
    }

    // Если есть ошибки, выводим их
    if (!empty($errors)) {
        echo "<h2>Ошибка:</h2><ul>";
        foreach ($errors as $error) {
            echo "<li>$error</li>";
        }
        echo "</ul>";
    } else {
        // Если ошибок нет, выводим отчет
        $part_name = $_POST["part_name"];
        $quantity = $_POST["quantity"];
        $report = "Вы заказали следующую запчасть: $part_name, в количестве $quantity шт.";
        echo "<h2>Отчет:</h2><p>$report</p>";
    }
}
?>

<!-- Форма для заказа запчастей -->
<h2>Форма заказа запчастей</h2>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    <label for="part_name">Название запчасти:</label><br>
    <input type="text" id="part_name" name="part_name"><br><br>
    <label for="quantity">Количество:</label><br>
    <input type="number" id="quantity" name="quantity"><br><br>
    <input type="submit" value="Отправить заказ">
</form>

</body>
</html>
