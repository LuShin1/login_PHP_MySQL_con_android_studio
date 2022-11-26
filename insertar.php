<?php
include 'conexion.php';

$nombre=$_POST['nombre'];
$usu_usuario=$_POST['usu_usuario'];
$usu_password=$_POST['usu_password'];

$query ="INSERT INTO usuario (nombre,usu_usuario,usu_password) values ('$nombre','$usu_usuario','$usu_password')";
$resultado =mysqli_query($conexion,$query);

if($resultado){
    echo "registrado";
}
else{
    echo "Error al registrar";
}


?>