<?php

function generate_array(&$arr, ?int $length) {
    $MIN_VAL = 0;
    $MAX_VAL = 20;

    for ($i = 0; $i < $length; ++$i) {
        array_push($arr, random_int($MIN_VAL, $MAX_VAL));
    }
}

function sum_of_even_positive($arr) {
    $sum = 0;

    foreach ($arr as $num) {
        if ($num > 0 && $num % 2 == 0) {
            $sum += $num;
        }
    }

    return $sum;
}

function print_array($arr) {
    foreach ($arr as $elem) {
        echo $elem . " | ";
    }
    echo "<br>";
}

function main() {
    $LENGTH_OF_ARR = 10;
    $arr = array();
    generate_array($arr, $LENGTH_OF_ARR);
    echo "массив: ";
    print_array($arr);
    $result = sum_of_even_positive($arr);
    echo "Сумма четных положительных элементов: $result";
}

main();

?>