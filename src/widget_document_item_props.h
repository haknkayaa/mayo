#pragma once

#include <QtWidgets/QWidget>
#include <vector>

class QtProperty;
class QtVariantPropertyManager;
class QtVariantProperty;

namespace Mayo {

class DocumentItem;
class GuiApplication;
class GpxDocumentItem;
class Property;

class WidgetDocumentItemProps : public QWidget
{
public:
    WidgetDocumentItemProps(QWidget* parent = nullptr);
    ~WidgetDocumentItemProps();

    void setGuiApplication(GuiApplication* guiApp);

    void editDocumentItems(const std::vector<DocumentItem*>& vecDocItem);

private:
    void connectPropertyValueChangeSignals(bool on);
    void onQVariantPropertyValueChanged(
            QtProperty *qtProp, const QVariant &value);

    void createQtProperties(
            const std::vector<Property*>& properties, QtProperty* parentProp);
    void mapProperty(QtVariantProperty* qtProp, Property* prop);

    struct QtProp_Prop {
        QtVariantProperty* qtProp;
        Property* prop;
    };

    GuiApplication* m_guiApp = nullptr;
    class Ui_WidgetDocumentItemProps* m_ui = nullptr;
    DocumentItem* m_currentDocItem = nullptr;
    GpxDocumentItem* m_currentGpxDocItem = nullptr;

    QtVariantPropertyManager* m_varPropMgr = nullptr;
    std::vector<QtProp_Prop> m_vecQtPropProp;
};

} // namespace Mayo
