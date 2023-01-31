<?php
define("TEMP_HOT", 25);
define("TEMP_COLD", 15);

echo "Quelle est la temperature ? ";
fscanf(STDIN, "%f", $temp);

if($temp > TEMP_HOT){
	echo 'chaud';
}elseif($temp >= TEMP_COLD){
	echo 'Tempéré';	
}else{
	echo 'Froid';
}
?>
