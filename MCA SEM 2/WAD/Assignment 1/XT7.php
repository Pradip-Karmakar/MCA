<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignmnet 1 XT7</title>
</head>
<body>
	<?php
	$file = 'files/7.txt';

	$fReadHandle = fopen("files/studinfo.txt", 'r+');
	$currentPosition = fgets($fReadHandle, 4);
	echo "<br> Reading from Start <br>" . $currentPosition;

	$currentPosition = fgets($fReadHandle, 5);
	echo "<br> Reading from the last read <br>" . $currentPosition;
	fseek($fReadHandle, 0);
	
	$currentPosition = fgets($fReadHandle, 4);
	echo "<br> Again Reading from Start <br>" . $currentPosition;
	
	$ftell = ftell($fReadHandle);
	echo '<br> $ftell' . " $ftell ";
	?>
</body>
</html>
