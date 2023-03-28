<?php
function doubler($a){
    return $a*2;
}

$resultat = intval($_POST["nombre"]);

$resultat = doubler($resultat);
?>
<html lang="fr">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Résultat</title>
    </head>
    <body>
        <p>Le double de <?= $_POST['nombre'] ?> est <?= $resultat ?>.</p>
        <br>
        <a href="exercice-doubler.php">Choisir un autre nombre</a>
    </body>
</html>