<?php
function calculateAverage($numbers)
{
    return array_sum($numbers) / count($numbers);
}

$testArray = [160, 109, 18];
echo calculateAverage($testArray);

?>