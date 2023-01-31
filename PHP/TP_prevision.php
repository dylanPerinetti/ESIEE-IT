<?php
echo 'Quel est le prénom ? ';
fscanf(STDIN, "%s", $user_name);
echo 'Quel est age à '.$user_name.' ? ';
fscanf(STDIN, "%d", $age_user);

echo 'Quelles est l\'année de référence ? ';
fscanf(STDIN, "%d", $reference_years);

echo 'Quelles est le décalage ? ';
fscanf(STDIN, "%d", $lag_year);

echo 'En '.($reference_years+$lag_year).', '.$user_name.' aura '.($age_user+$lag_year)." ans\n";
?>
