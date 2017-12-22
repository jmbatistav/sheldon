# Sheldon 0.5

El código está liberado bajo la GNU General Public License.
__________

# Summary

Esta es la versión 0.5 de Sheldon, un herramienta para la descarga los repositorios de las distribuciones basadas en Debian GNU/Linux utilizando apt-mirror.

# Developed By

* __José Manuel Batista Viltre, UCI__ - <batista87@gmail.com>
    * Desarrollador principal (hasta el momento el único)

# How to debianize Sheldon

### Dependencies

debhelper
make
g++
build-essential
cdbs
libqtcore4, libqtgui4 | libqt5core5a, libqt5gui5, libqt5widgets5

### Debianize

``` bash
qmake CONFIG+=release
dpkg-buildpackage -rfakeroot -d -us -uc
```

# How to use Sheldon

1. Ejecutar la aplicación desde el menú Applications/Network/FileTransfer.
2. Seleccionar la ruta donde desea descargar el/los repositorio/s desde el botón _Examinar_.
3. Especificar que repositorio/s desea descargar indicandole que tipo de arquitectura _i386_, _amd64_, etc. Ejemplo:

```
deb-i386 http://debian.uci.cu/debian wheezy main
deb-amd64 http://debian.uci.cu/debian testing main
```
4. Aplicar los cambios y en la siguiente pestaña _Iniciar_ el proceso.
5. Sentarse a esperar.
