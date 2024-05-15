<?php

class Fractions {
    private $m_integer_part;
    private $m_fractional_part;

    private function convert_float_to_int($number) {
        $number_str = strval($number);
        $number_str = str_replace(".", "", $number_str);
        return intval($number_str);
    }
        

    public function __construct($m_integer_part, $m_fractional_part) {
        $this->m_integer_part = $m_integer_part;
        $this->m_fractional_part = $m_fractional_part;
    }

    public function add(?Fractions $other) {
        $result = new Fractions(0, 0);
        $result->m_integer_part = $this->m_integer_part + $other->m_integer_part;
        
        $fractionalSum = $this->m_fractional_part + $other->m_fractional_part;
        $result->m_fractional_part = $fractionalSum % 100; 
        $result->m_integer_part += floor($fractionalSum / 100);
        
        return $result;
    }

    public function sub(?Fractions $other) {
        $result = new Fractions(0, 0);
        $result->m_integer_part = $this->m_integer_part - $other->m_integer_part;
        
        $fractional_diff = $this->m_fractional_part - $other->m_fractional_part;
        if ($fractional_diff < 0) {
            $result->m_integer_part -= 1;
            $fractional_diff += 100;
        }
        $result->m_fractional_part = $fractional_diff;
        
        return $result;
    }

    public function mul(?Fractions $other) {
        $result = new Fractions(0, 0);
        
        $result->m_integer_part = $this->m_integer_part * $other->m_integer_part;
        $result->m_fractional_part = $this->m_integer_part * $other->m_fractional_part + $other->m_integer_part * $this->m_fractional_part + $this->m_fractional_part * $other->m_fractional_part / 100;
        $result->m_fractional_part = $this->convert_float_to_int($result->m_fractional_part);
        
        return $result;
    }

    public function compare(?Fractions $other) {
        $epsilon = 0.0001; 
    
        $integerEqual = $this->m_integer_part == $other->m_integer_part;
    
        $fractionalEqual = abs($this->m_fractional_part - $other->m_fractional_part) < $epsilon;
    
        return $integerEqual && $fractionalEqual;
    }

    public function integer_part() {
        return $this->m_integer_part;
    }

    public function fractional_part() {
        return $this->m_fractional_part;
    }
}

$fraction1 = new Fractions(3, 25);
$fraction2 = new Fractions(2, 50);

$result = $fraction1->add($fraction2);
echo "Додавання: ".$result->integer_part().".".$result->fractional_part()."<br>";  // Очікується: 0.75

$result = $fraction1->sub($fraction2);
echo "Віднімання: ".$result->integer_part().".".$result->fractional_part()."<br>";  // Очікується: 5.75

$result = $fraction1->mul($fraction2);
echo "Множення: ".$result->integer_part().".".$result->fractional_part()."<br>";  // Очікується: -6.125

if ($fraction1->compare($fraction2)) {
    echo "дробі еквівалентні";
}
else {
    echo "дробі НЕ еквівалентні";
}

?>