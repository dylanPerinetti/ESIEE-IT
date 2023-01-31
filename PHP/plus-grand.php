<?php
echo "Premier nombre ? ";
fscanf(STDIN, "%d", $first_nb_input);

echo "Second nombre ? ";
fscanf(STDIN, "%d", $second_nb_input);

echo 'Le plus Grand = ';
if($first_nb_input >= $second_nb_input){
	echo $first_nb_input;
}else
{
	echo $second_nb_input;
}
?>