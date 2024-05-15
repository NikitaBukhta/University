<?php

interface Dancer {
    public function dance();
}

class DiscoDancer implements Dancer {
    public function dance() {
        echo "Танцует Диско<br>";
    }
}

class BallroomDancer implements Dancer {
    public function dance() {
        echo "Танцует Балет<br>";
    }
}

function main() {
    $ARR_SIZE = 20;
    $arr = array();

    for ($i = 0; $i < $ARR_SIZE; ++$i) {
        $dancer = random_int(0, 1) ? new DiscoDancer() : new BallroomDancer();
        array_push($arr, $dancer);
    }

    foreach ($arr as $dancer) {
        $dancer->dance();
    }
}

main();

?>
