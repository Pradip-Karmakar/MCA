<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT6</title>
</head>
<body>
<?php
	if(file_exists("files/studinfo.txt")) {
		$f1Handle = @fopen("files/studinfo.txt", "rb");
		echo fread($f1Handle, filesize('files/studinfo.txt'));
		$fn = fopen("files/studinfo.txt","r");
		while(! feof($fn))  {
			$result = fgets($fn);
			echo "<br>" . $result;
		}
		fclose($fn);
		fclose($f1Handle);
	} 
	else {
		echo "No such File Exists";
	}
?>
</body>
</html>
