<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT1</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
		<h1>PRN FINDER</h1>
		<form method="POST" name="form1">
			<div>
				<input type="number" name="p" placeholder="Enter Amount">
			</div>
			<div>
				<input type="number" name="r" placeholder="Enter Rate Of Interest">
			</div>
			<div>
				<input type="number" name="n" placeholder="Enter No of years">
			</div>
			<div>
				<button class="submit" name="submit"> Submit </button>
			</div>
		</form>
	</div>
	<?php
		if(isset($_POST['submit'])){
			echo "<center>";	
			$prn = ($_POST['p'] * $_POST['r'] * $_POST['n']) / 100;
			echo "<h2> $prn </h2>";
			echo "</center>";
		}
	?>
</body>
</html>