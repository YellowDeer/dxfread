# dxfread
Отображение примитивов из файла .dxf (линии, круги, дуги). 
Использована Qt  6.1.2., Cmake.
Кслассы ContainerElem, FileReader, FabricElem, Elements отвечают за логику работы с примитивами и не используют Qt.
Класс DrawerElem - интерфейс отвечающий за отрисовку.
