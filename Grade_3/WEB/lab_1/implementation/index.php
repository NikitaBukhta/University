<?php
use \DateTime;

function task_1() {
    echo "Bukhta Mykyta - Task_1<br>";

    $first_name = "Mykyta";
    $second_name = "Bukhta";
    $full_name = "$first_name $second_name";
    echo "$full_name with len: ", strlen($full_name), "<br>";
}

function task_2() {
    echo "<br>Bukhta Mykyta - Task_2<br>";
    $num = 1;
    $power_of_two = 2;

    echo "Числа от 1 до 5:<br>";
    while ($num <= 5) {
        echo $num . " ";
        $num++;
    }
    echo "<br>";

    echo "Степени числа 2 от 2^1 до 2^5:<br>";
    while ($power_of_two <= 32) {
        echo $power_of_two . " ";
        $power_of_two *= 2;
    }
    echo "<br>";
}

function task_3() {
    echo "<br>Bukhta Mykyta - Task_3<br>";

    $SECONDS_IN_MINUTE = 60;
    $MINUTES_IN_HOUR = 60;
    $HOURS_IN_DAY = 24;
    $AVARAGE_DAYS_IN_MONTH = 30;

    $SECOND_IN_HOUR = $SECONDS_IN_MINUTE * $MINUTES_IN_HOUR;
    $SECONDS_IN_DAY = $SECOND_IN_HOUR * $HOURS_IN_DAY;
    $SECONDS_IN_MONTH = $SECONDS_IN_DAY * $AVARAGE_DAYS_IN_MONTH;

    echo "Секунд в часе: $SECOND_IN_HOUR<br>";
    echo "Секунд в сутках: $SECONDS_IN_DAY<br>";
    echo "Секунд в месяце в среднем: $SECONDS_IN_MONTH<br>";
}

function task_4() {
    echo "<br>Bukhta Mykyta - Task_4<br>";

    $MIN_VALUE = 0;
    $MAX_VALUE = 59;
    $random_minute = random_int($MIN_VALUE, $MAX_VALUE);
    $quarter = ceil($random_minute / 15);
    $quarter = $quarter ? $quarter : 1;     // if quarter is 0 move it should have value 1; 

    echo "$random_minute находится в $quarter четверти<br>";
}

function task_5() {
    echo "<br>Bukhta Mykyta - Task_5<br>";

    $RUS = "ru";
    $ENG = "en";
    $LANGUAGES = array($RUS, $ENG);
    $DAY_OF_WEEK_LANG_VAR = array(
        $RUS => array("Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"),
        $ENG => array("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday")
    );

    $cur_language = $LANGUAGES[array_rand($LANGUAGES)];
    $arr = $DAY_OF_WEEK_LANG_VAR[$cur_language];

    echo "Текущий язык: $cur_language<br>";
    foreach ($arr as $day) {
        echo "$day, ";
    }
    echo "<br>";
}

function task_6() {
    echo "<br>Bukhta Mykyta - Task_6<br>";

    $MIN_VALUE = 1;
    $MAX_VALUE = 4;

    $SEASONS = array(
        "Зима", "Весна", "Лето", "Осень"
    );

    $random_season_val = random_int($MIN_VALUE, $MAX_VALUE);
    echo "Номер сезона: $random_season_val <br>";
    echo "Сезон: " . $SEASONS[$random_season_val - 1] . "<br>";
}

function task_7() {
    echo "<br>Bukhta Mykyta - Task_7<br>";

    $MIN_VAL = 1;
    $MAX_VAL = 31;
    $DECADE_LENGTH = 10;
    $MAX_DECADE_VAL = 3;

    $random_day = random_int($MIN_VAL, $MAX_VAL);
    $decade_val = ceil($random_day / $DECADE_LENGTH);

    $decade_val = $decade_val > $MAX_DECADE_VAL ? $MAX_DECADE_VAL : $decade_val;

    echo "день $random_day находится в $decade_val декаде <br>";
}

function task_8() {
    echo "<br>Bukhta Mykyta - Task_8<br>";

    $LEAN_YEAR_PERIOD = 4;
    $random_year = random_int(PHP_INT_MIN, PHP_INT_MAX);

    echo "Год $random_year это ";
    if ($random_year % $LEAN_YEAR_PERIOD != 0) {
        echo "не ";
    }
    echo "высокосный год <br>";
}

function task_9() {
    echo "<br>Bukhta Mykyta - Task_9<br>";

    $current_date = new DateTime();
    $current_hour = $current_date->format('G');

    echo "Сейчас $current_hour часов. ";
    if ($current_hour >= 6 && $current_hour < 12) {
        echo "Доброе утро! Время начать день с энергичного завтрака.";
    } elseif ($current_hour >= 12 && $current_hour < 18) {
        echo "Добрый день! Пора обедать и продолжить дела.";
    } elseif ($current_hour >= 18 && $current_hour < 22) {
        echo "Добрый вечер! Пора ужинать и отдыхать.";
    } else {
        echo "Доброй ночи! Время ложиться спать и готовиться к новому дню.";
    }
    echo "<br>";
}

function task_10() {
    echo "<br>Bukhta Mykyta - Task_10<br>";

    $MIN_VAL = -100;
    $MAX_VAL = 100;

    $first = random_int($MIN_VAL, $MAX_VAL);
    $second = random_int($MIN_VAL, $MAX_VAL);
    $sum_of_pow2 = pow($first, 2) + pow($second, 2);

    echo "$first^2 + $second^2 = $sum_of_pow2<br>";
}

function task_11() {
    echo "<br>Bukhta Mykyta - Task_11<br>";

    $MIN_VAL = -100;
    $MAX_VAL = 100;
    $NUMBERS_ARR_LIMIT = 3;

    $numbers_arr = array();

    for ($i = 0; $i < $NUMBERS_ARR_LIMIT; ++$i) {
        array_push($numbers_arr, random_int($MIN_VAL, $MAX_VAL));
    }

    $numbers_sum = array_sum($numbers_arr);
    $avarage = $numbers_sum / count($numbers_arr);

    echo "Средняя арифметическая чисел ";
    foreach ($numbers_arr as $val) {
        echo "$val, ";
    }
    echo " = $avarage <br>";
}

function task_12() {
    echo "<br>Bukhta Mykyta - Task_12<br>";

    $MIN_VAL = -100;
    $MAX_VAL = 100;
    $NUMBERS_ARR_LIMIT = 3;

    $numbers_arr = array();
    for ($i = 0; $i < $NUMBERS_ARR_LIMIT; ++$i) {
        $random_val = 0;

        // Генерируем случайное число, исключая ноль
        do {
            $random_val = random_int($MIN_VAL, $MAX_VAL);
        } while ($random_val == 0);

        array_push($numbers_arr, $random_val);
    }

    $results = [];
    $count = count($numbers_arr);
    
    // Перебираем каждое число
    for ($i = 0; $i < $count - 1; $i++) {
        for ($j = $i + 1; $j < $count; $j++) {
            // Находим сумму двух чисел и определяем третье число
            $sum = $numbers_arr[$i] + $numbers_arr[$j];
            
            // Перебираем каждое оставшееся третье число
            for ($k = 0; $k < $count; $k++) {
                if ($k != $i && $k != $j) {
                    // Делаем деление суммы на текущее третье число и добавляем результат в список
                    $res = $sum / $numbers_arr[$k];
                    array_push($results, $res);
                }
            }
        }
    }

    echo "Числа: ";
    foreach ($numbers_arr as $val) {
        echo "$val, ";
    }
    echo "Всевозможные результаты деления суммы двух из трех чисел на оставшееся третье число:<br>";
    foreach ($results as $res) {
        echo "$res | ";
    }
    echo "<br>";
}

function task_13() {
    echo "<br>Bukhta Mykyta - Task_13<br>";

    $MIN_VAL = -100;
    $MAX_VAL = 100;

    $first = random_int($MIN_VAL, $MAX_VAL);
    $second = random_int($MIN_VAL, $MAX_VAL);

    $first_40_per = $first / 100 * 40;
    $second_84_per = $second / 100 * 84;

    echo "40% от $first это $first_40_per <br>";
    echo "84% от $second это $second_84_per <br>";
}

function task_14() {
    echo "<br>Bukhta Mykyta - Task_14<br>";

    $MIN_VAL = -100;
    $MAX_VAL = 100;
    $number = random_int($MIN_VAL, $MAX_VAL);

    echo "Число $number стало ";

    if ($number > 10) {
        $number += 100;
    } else {
        $number -= 30;
    }

    echo "$number <br>";
}

function task_15() {
    echo "<br>Bukhta Mykyta - Task_15<br>";

    $MIN_VAL = -100;
    $MAX_VAL = 100;
    $number = random_int($MIN_VAL, $MAX_VAL);

    echo "Число $number стало ";

    if ($number % 2 == 0) {
        // Если число четное, уменьшаем его в 2 раза
        $number /= 2;
    } else {
        // Иначе увеличиваем его в 3 раза
        $number *= 3;
    }

    echo "$number <br>";
}

task_1();
task_2();
task_3();
task_4();
task_5();
task_6();
task_7();
task_8();
task_9();
task_10();
task_11();
task_12();
task_13();
task_14();
task_15();
?>