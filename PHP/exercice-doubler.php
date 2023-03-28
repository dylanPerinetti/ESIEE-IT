<?php
$title = "Exercice doubler";
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
        <form action="doubler-resultat.php" method="post">
            Nombre :
            <input type="text" name="nombre">
            <br>
            <br>
            <input type="submit" value="doubler">
        </form>
    </body>
</html>