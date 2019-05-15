#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readXML()
{
    QFile file("test.xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }

    QDomElement root = doc.documentElement();
    qDebug() << root.nodeName();
    QDomNode node = root.firstChild();
    while(!node.isNull())
    {
        if(node.isElement())
        {
            QDomElement e = node.toElement();
            qDebug() << e.tagName() << " " << e.attribute("id") << " "
            << e.attribute("time");
            QDomNodeList list = e.childNodes();
            for(int i= 0; i < list.count(); ++i)
            {
                QDomNode n = list.at(i);
                if(n.isElement()){
                    qDebug() << n.nodeName() <<":" << n.toElement().text();
                }
            }
        }
        node = node.nextSibling();
    }
}

void Widget::writeXML()
{
    QFile file("test.xml");
    if(!file.open(QFile::WriteOnly | QFile::Truncate))
        return;
    QDomDocument doc;
    // xml head
    QDomProcessingInstruction instruction; //instrunction
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    // root node
    QDomElement root = doc.createElement("library");
    doc.appendChild(root);
    // first child and element
    QDomElement book = doc.createElement("book");
    book.setAttribute("id", 1); // manner 1 create attribute, value various type
    QDomAttr time  = doc.createAttribute("time"); // manner 2 create attr, value must be string
    time.setValue("2019/5/14");
    book.setAttributeNode(time);
    QDomElement title = doc.createElement("title");
    QDomText text;
    text = doc.createTextNode("c++ primer");
    book.appendChild(title);
    title.appendChild(text);
    QDomElement author = doc.createElement("author");
    text = doc.createTextNode("Stanley Lippman");
    author.appendChild(text);
    book.appendChild(author);
    root.appendChild(book);

    book = doc.createElement("book");
    book.setAttribute("id", 2);
    time = doc.createAttribute("time");
    time.setValue("2019/05/15");
    book.setAttributeNode(time);
    title = doc.createElement("title");
    text = doc.createTextNode("Thinking in Java");
    book.appendChild(title);
    title.appendChild(text);
    author = doc.createElement("author");
    text = doc.createTextNode("Bruce Eckel");
    book.appendChild(author);
    author.appendChild(text);
    root.appendChild(book);

    //output big file
    QTextStream out(&file);
    doc.save(out, 4);
    file.close();

}

void Widget::on_pushButton_clicked()
{
    writeXML();
}

void Widget::on_pushButton_2_clicked()
{
    readXML();
}
