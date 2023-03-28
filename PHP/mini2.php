<?php
$title = "Exercice mini2";
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
        <form action="mini2-resultat.php" method="get">
            Nombre :
            <input type="text" name="nombre1">
            <br>
            <br>
            Nombre :
            <input type="text" name="nombre2">
            <br>
            <br>
            <input type="submit" value="doubler">
        </form>
    </body>
</html>