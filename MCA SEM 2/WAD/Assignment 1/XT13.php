<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT13</title>
</head>
<body>
	<?php
	$i = 0;
	if(file_exists("files/studinfo.txt")) {
		$f1Handle = @fopen("files/studinfo.txt", "rb");
		
		$fn = fopen("files/studinfo.txt","r");
		while(! feof($fn))  {
			$array[$i++] = fgets($fn);
		}
		fclose($fn);
		echo '<table border="1" style="border: solid 3px #808080;">';
		while($i--) {
			echo "<tr>";
			echo "<td>";
			echo $array[$i];
			echo "</td>";
			echo "</tr>";
		}
		echo "</table>";
		fclose($f1Handle);
	} else {
		echo "No such File Exists";
	}
	?>
</body>
</html>	
