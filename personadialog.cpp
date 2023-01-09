#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    if(ui->inNombre->text().isEmpty())
    {
        QMessageBox::warning(this,"Guardar contactos","No hay nombre que guardar");
        return;
    }
    if(ui->inApellido->text().isEmpty())
    {
        QMessageBox::warning(this,"Guardar contactos","No hay apellido que guardar");
        return;
    }
    if(ui->inTelefono->text().isEmpty())
    {
        QMessageBox::warning(this,"Guardar contactos","No hay telefono que guardar");
        return;
    }
    if(ui->inEmail->text().isEmpty())
    {
        QMessageBox::warning(this,"Guardar contactos","No hay email que guardar");
        return;
    }
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();
    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}
