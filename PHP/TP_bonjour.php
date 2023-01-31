<?php
echo 'Quel est votre prénom : ';
fscanf(STDIN, "%s", $name_user);
echo 'Bonjour '.$name_user;

echo "\nQuel est age à tu ? ";
fscanf(STDIN, "%d", $age_user);
echo 'Tu as '.$age_user.' ans';
echo 'Dans un an, tu auras '.($age_user+1).' ans';
?>
