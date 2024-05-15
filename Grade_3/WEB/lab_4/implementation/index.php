<?php 

require_once("element_counter.php");

function main() {
    $ARR_SIZE = 20;
    $MIN_VAL = -25;
    $MAX_VAL = 10;
    
    $arr = array();

    for ($i = 0; $i < $ARR_SIZE; ++$i) {
        $arr[] = rand($MIN_VAL, $MAX_VAL);
    }
    
    echo "Сгенерированный массив: " . implode(', ', $arr) . "<br>";
    $count = count_elements_less_than_min_abs($arr);
    echo "Количество элементов по модулю меньших, чем минимальный: $count<br>";
}

main();

?>