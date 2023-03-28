<?php
function bissextile($a) :bool{
    if (!($a%4))
        if (!($a%100))
            if(!($a%400))return true;
            else return false;
        else
            return true;
    else
        return false;
}

$annee = intval($_GET["annee"]);

if (bissextile($annee))
    $resultat = "bissextile";
else
    $resultat = "non bissextile";
?>
<html lang="fr">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Résultat</title>
    </head>
    <body>
        <p>L'année <?= $annee ?> est <?= $resultat ?>.</p>
        <br>
        <a href="bissextile.php">Choisir un autre nombre</a>
    </body>
</html>