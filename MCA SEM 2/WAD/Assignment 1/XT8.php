<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT8</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
		<h2>Hobby Selector</h2>
		<form method="POST">
			<div>
				<input type="checkbox" id="h1" name="hobby[]" value="Gaming"> Gaming
				<input type="checkbox" id="h2" name="hobby[]" value="Study"> Study
				<input type="checkbox" id="h3" name="hobby[]" value="Sleeping"> Sleeping
				<input type="checkbox" id="h3" name="hobby[]" value="Riding"> Riding
				<input type="checkbox" id="h3" name="hobby[]" value="Travelling"> Travelling
			</div>
			<div>
				<button class="submit" name="submit"> Submit </button>
			</div>
		</form>
		<?php
			if(isset($_POST['submit'])){
				if(!empty($_POST['hobby'])){
					foreach($_POST['hobby'] as $selected){
						echo $selected."</br>";
					}
				}
			}
		?>
	</div>
</body>
</html>