<?php
$first_nb_input = intval($_GET['nombre1']);
$second_nb_input = intval($_GET['nombre2']);

function mini($first,$second){
if($first <= $second)
	return $first;
else
	return $second;
}

$low_nombre = mini($first_nb_input,$second_nb_input);
?>
<html lang="fr">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Résultat</title>
    </head>
    <body>
        <p>Le minimum de <?= $first_nb_input ?> et <?= $second_nb_input ?> est <?= $low_nombre ?>.</p>
        <br>
        <a href="mini2.php">Choisir un autre nombre</a>
    </body>
</html>