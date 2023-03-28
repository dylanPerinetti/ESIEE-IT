<?php
$title = "Exercice bissextile";
?>
<!DOCTYPE html>
<html lang="fr">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title><?= $title ?></title>
    </head>
    <body>
        <h1><?= $title ?></h1>
        <form action="bissextile-resultat.php" method="get">
            Année >1582 :
            <input type="number" name="annee" min="1582">
            <br>
            <br>
            <input type="submit" value="Tester">
        </form>
    </body>
</html>