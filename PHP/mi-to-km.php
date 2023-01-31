<?php
define("MI_TO_KM", 1.60934);

$VariableEnMiH = 180;
$VariableEnKmH = $VariableEnMiH * MI_TO_KM;


echo 'Une vitesse de '.$VariableEnMiH .' mi/h est égale à '.$VariableEnKmH.'km/h';

?>