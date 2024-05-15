<?php

function count_elements_less_than_min_abs($arr) {
    $min_val = min($arr);
    $count = 0;
    foreach ($arr as $num) {
        if (abs($num) < abs($min_val)) {
            $count++;
        }
    }
    return $count;
}

?>