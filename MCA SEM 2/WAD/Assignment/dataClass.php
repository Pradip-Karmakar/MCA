<?php

class Dataclass
{
    
	private $conn;


    public function __construct()
    {
       $this->conn=mysqli_connect("localhost","root","","wad") or die('connection Failed');
    }
    public function getConn()
    {
        return $this->conn;
    }

    public function saveRecord($query)
    {
    	$res=mysqli_query($this->conn,$query);
	    return $res;
    }

    public function getTable($query)
    {
    	$table = mysqli_query($this->conn,$query);

    	return $table;
    }

    public function getRow($query)
    {
    	$table = mysqli_query($this->conn,$query);
    	$row = mysqli_fetch_assoc($table);
    	return $row;
    }
}

?>