<?php
define("RECALE", 10);
define("PASSABLE", 12);
define("ASSEZ_BIEN", 14);
define("BIEN", 16);

echo "Note 1 : ";
fscanf(STDIN, "%f", $note1);
echo "Note 2 : ";
fscanf(STDIN, "%f", $note2);
echo "Note 3 : ";
fscanf(STDIN, "%f", $note3);

$moyenne = ($note1+$note2+$note3)/3.0;

echo 'La moyenne des notes( 1, 2 et 3 ) est '.round($moyenne,2)."\n";

if($moyenne < RECALE){
	echo 'Reclé';
}elseif($moyenne < PASSABLE){
	echo 'Passable';	
}elseif($moyenne < ASSEZ_BIEN){
	echo 'Assez bien';
}elseif($moyenne < BIEN){
	echo 'Bien';
}else{
	echo 'Très bien';
}

echo "\n";
?>