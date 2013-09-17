/* def-reader.c generated by valac 0.20.1, the Vala compiler
 * generated from def-reader.vala, do not modify */

/* 
 * SmartSim - Digital Logic Circuit Designer and Simulator
 *   
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *   
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *   
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *   
 *   Filename: componentdef/def-reader.vala
 *   
 *   Copyright Ashley Newson 2013
 */

#include <glib.h>
#include <glib-object.h>
#include <cairo.h>
#include <libxml/tree.h>
#include <libxml/xmlwriter.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <config.h>
#include <stdio.h>


#define TYPE_COMPONENT_DEF (component_def_get_type ())
#define COMPONENT_DEF(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPONENT_DEF, ComponentDef))
#define COMPONENT_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPONENT_DEF, ComponentDefClass))
#define IS_COMPONENT_DEF(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPONENT_DEF))
#define IS_COMPONENT_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPONENT_DEF))
#define COMPONENT_DEF_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPONENT_DEF, ComponentDefClass))

typedef struct _ComponentDef ComponentDef;
typedef struct _ComponentDefClass ComponentDefClass;
typedef struct _ComponentDefPrivate ComponentDefPrivate;

#define TYPE_DIRECTION (direction_get_type ())

#define TYPE_COMPONENT_INST (component_inst_get_type ())
#define COMPONENT_INST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPONENT_INST, ComponentInst))
#define COMPONENT_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPONENT_INST, ComponentInstClass))
#define IS_COMPONENT_INST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPONENT_INST))
#define IS_COMPONENT_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPONENT_INST))
#define COMPONENT_INST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPONENT_INST, ComponentInstClass))

typedef struct _ComponentInst ComponentInst;
typedef struct _ComponentInstClass ComponentInstClass;

#define TYPE_CUSTOM_COMPONENT_DEF (custom_component_def_get_type ())
#define CUSTOM_COMPONENT_DEF(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CUSTOM_COMPONENT_DEF, CustomComponentDef))
#define CUSTOM_COMPONENT_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CUSTOM_COMPONENT_DEF, CustomComponentDefClass))
#define IS_CUSTOM_COMPONENT_DEF(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CUSTOM_COMPONENT_DEF))
#define IS_CUSTOM_COMPONENT_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CUSTOM_COMPONENT_DEF))
#define CUSTOM_COMPONENT_DEF_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CUSTOM_COMPONENT_DEF, CustomComponentDefClass))

typedef struct _CustomComponentDef CustomComponentDef;
typedef struct _CustomComponentDefClass CustomComponentDefClass;

#define TYPE_PROPERTY_ITEM (property_item_get_type ())
#define PROPERTY_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROPERTY_ITEM, PropertyItem))
#define PROPERTY_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROPERTY_ITEM, PropertyItemClass))
#define IS_PROPERTY_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROPERTY_ITEM))
#define IS_PROPERTY_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROPERTY_ITEM))
#define PROPERTY_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROPERTY_ITEM, PropertyItemClass))

typedef struct _PropertyItem PropertyItem;
typedef struct _PropertyItemClass PropertyItemClass;

#define TYPE_PROPERTY_SET (property_set_get_type ())
#define PROPERTY_SET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROPERTY_SET, PropertySet))
#define PROPERTY_SET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROPERTY_SET, PropertySetClass))
#define IS_PROPERTY_SET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROPERTY_SET))
#define IS_PROPERTY_SET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROPERTY_SET))
#define PROPERTY_SET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROPERTY_SET, PropertySetClass))

typedef struct _PropertySet PropertySet;
typedef struct _PropertySetClass PropertySetClass;

#define TYPE_COMPILED_CIRCUIT (compiled_circuit_get_type ())
#define COMPILED_CIRCUIT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPILED_CIRCUIT, CompiledCircuit))
#define COMPILED_CIRCUIT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPILED_CIRCUIT, CompiledCircuitClass))
#define IS_COMPILED_CIRCUIT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPILED_CIRCUIT))
#define IS_COMPILED_CIRCUIT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPILED_CIRCUIT))
#define COMPILED_CIRCUIT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPILED_CIRCUIT, CompiledCircuitClass))

typedef struct _CompiledCircuit CompiledCircuit;
typedef struct _CompiledCircuitClass CompiledCircuitClass;

#define TYPE_CONNECTION (connection_get_type ())
#define CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CONNECTION, Connection))
#define CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CONNECTION, ConnectionClass))
#define IS_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CONNECTION))
#define IS_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CONNECTION))
#define CONNECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CONNECTION, ConnectionClass))

typedef struct _Connection Connection;
typedef struct _ConnectionClass ConnectionClass;

#define TYPE_CIRCUIT_INFORMATION (circuit_information_get_type ())
#define CIRCUIT_INFORMATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CIRCUIT_INFORMATION, CircuitInformation))
#define CIRCUIT_INFORMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CIRCUIT_INFORMATION, CircuitInformationClass))
#define IS_CIRCUIT_INFORMATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CIRCUIT_INFORMATION))
#define IS_CIRCUIT_INFORMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CIRCUIT_INFORMATION))
#define CIRCUIT_INFORMATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CIRCUIT_INFORMATION, CircuitInformationClass))

typedef struct _CircuitInformation CircuitInformation;
typedef struct _CircuitInformationClass CircuitInformationClass;

#define TYPE_GRAPHIC (graphic_get_type ())
#define GRAPHIC(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GRAPHIC, Graphic))
#define GRAPHIC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_GRAPHIC, GraphicClass))
#define IS_GRAPHIC(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GRAPHIC))
#define IS_GRAPHIC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_GRAPHIC))
#define GRAPHIC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_GRAPHIC, GraphicClass))

typedef struct _Graphic Graphic;
typedef struct _GraphicClass GraphicClass;

#define TYPE_PIN_DEF (pin_def_get_type ())
#define PIN_DEF(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PIN_DEF, PinDef))
#define PIN_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PIN_DEF, PinDefClass))
#define IS_PIN_DEF(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PIN_DEF))
#define IS_PIN_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PIN_DEF))
#define PIN_DEF_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PIN_DEF, PinDefClass))

typedef struct _PinDef PinDef;
typedef struct _PinDefClass PinDefClass;

#define TYPE_READER_COMPONENT_DEF (reader_component_def_get_type ())
#define READER_COMPONENT_DEF(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_READER_COMPONENT_DEF, ReaderComponentDef))
#define READER_COMPONENT_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_READER_COMPONENT_DEF, ReaderComponentDefClass))
#define IS_READER_COMPONENT_DEF(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_READER_COMPONENT_DEF))
#define IS_READER_COMPONENT_DEF_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_READER_COMPONENT_DEF))
#define READER_COMPONENT_DEF_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_READER_COMPONENT_DEF, ReaderComponentDefClass))

typedef struct _ReaderComponentDef ReaderComponentDef;
typedef struct _ReaderComponentDefClass ReaderComponentDefClass;
typedef struct _ReaderComponentDefPrivate ReaderComponentDefPrivate;
#define _component_def_unref0(var) ((var == NULL) ? NULL : (var = (component_def_unref (var), NULL)))

#define TYPE_WIRE_INST (wire_inst_get_type ())
#define WIRE_INST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_WIRE_INST, WireInst))
#define WIRE_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_WIRE_INST, WireInstClass))
#define IS_WIRE_INST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_WIRE_INST))
#define IS_WIRE_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_WIRE_INST))
#define WIRE_INST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_WIRE_INST, WireInstClass))

typedef struct _WireInst WireInst;
typedef struct _WireInstClass WireInstClass;
typedef struct _ComponentInstPrivate ComponentInstPrivate;

#define TYPE_PIN_INST (pin_inst_get_type ())
#define PIN_INST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PIN_INST, PinInst))
#define PIN_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PIN_INST, PinInstClass))
#define IS_PIN_INST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PIN_INST))
#define IS_PIN_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PIN_INST))
#define PIN_INST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PIN_INST, PinInstClass))

typedef struct _PinInst PinInst;
typedef struct _PinInstClass PinInstClass;
typedef struct _PinInstPrivate PinInstPrivate;
#define _connection_unref0(var) ((var == NULL) ? NULL : (var = (connection_unref (var), NULL)))

#define TYPE_COMPONENT_STATE (component_state_get_type ())
#define COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPONENT_STATE, ComponentState))
#define COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPONENT_STATE, ComponentStateClass))
#define IS_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPONENT_STATE))
#define IS_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPONENT_STATE))
#define COMPONENT_STATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPONENT_STATE, ComponentStateClass))

typedef struct _ComponentState ComponentState;
typedef struct _ComponentStateClass ComponentStateClass;

#define TYPE_READER_COMPONENT_STATE (reader_component_state_get_type ())
#define READER_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_READER_COMPONENT_STATE, ReaderComponentState))
#define READER_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_READER_COMPONENT_STATE, ReaderComponentStateClass))
#define IS_READER_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_READER_COMPONENT_STATE))
#define IS_READER_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_READER_COMPONENT_STATE))
#define READER_COMPONENT_STATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_READER_COMPONENT_STATE, ReaderComponentStateClass))

typedef struct _ReaderComponentState ReaderComponentState;
typedef struct _ReaderComponentStateClass ReaderComponentStateClass;
#define _component_state_unref0(var) ((var == NULL) ? NULL : (var = (component_state_unref (var), NULL)))

typedef enum  {
	DIRECTION_NONE,
	DIRECTION_RIGHT,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_HORIZONTAL,
	DIRECTION_VERTICAL,
	DIRECTION_DIAGONAL
} Direction;

struct _ComponentDef {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ComponentDefPrivate * priv;
	Graphic* graphic;
	gchar* name;
	gchar* description;
	gchar* iconFilename;
	gchar* label;
	PinDef** pinDefs;
	gint pinDefs_length1;
	gint rightBound;
	gint downBound;
	gint leftBound;
	gint upBound;
	gint backgroundAlpha;
	gint backgroundRed;
	gint backgroundGreen;
	gint backgroundBlue;
	gdouble backgroundAlphaF;
	gdouble backgroundRedF;
	gdouble backgroundGreenF;
	gdouble backgroundBlueF;
	gboolean drawBox;
	gchar* filename;
};

struct _ComponentDefClass {
	GTypeClass parent_class;
	void (*finalize) (ComponentDef *self);
	void (*extra_render) (ComponentDef* self, cairo_t* context, Direction direction, gboolean flipped, ComponentInst* componentInst);
	void (*extra_validate) (ComponentDef* self, CustomComponentDef** componentChain, int componentChain_length1, ComponentInst* componentInst);
	void (*add_properties) (ComponentDef* self, PropertySet* queryProperty, PropertySet* configurationProperty);
	void (*get_properties) (ComponentDef* self, PropertySet* queryProperty, PropertySet** configurationProperty);
	void (*load_properties) (ComponentDef* self, xmlNode* xmlnode, PropertySet** configurationProperty);
	void (*save_properties) (ComponentDef* self, xmlTextWriter* xmlWriter, PropertySet* configurationProperty);
	void (*configure_inst) (ComponentDef* self, ComponentInst* componentInst, gboolean firstLoad);
	void (*compile_component) (ComponentDef* self, CompiledCircuit* compiledCircuit, ComponentInst* componentInst, Connection** connections, int connections_length1, ComponentInst** ancestry, int ancestry_length1);
	void (*create_information) (ComponentDef* self, CircuitInformation* circuitInformation);
};

struct _ReaderComponentDef {
	ComponentDef parent_instance;
	ReaderComponentDefPrivate * priv;
};

struct _ReaderComponentDefClass {
	ComponentDefClass parent_class;
};

typedef enum  {
	COMPONENT_DEF_LOAD_ERROR_NOT_COMPONENT,
	COMPONENT_DEF_LOAD_ERROR_FILE,
	COMPONENT_DEF_LOAD_ERROR_LOAD
} ComponentDefLoadError;
#define COMPONENT_DEF_LOAD_ERROR component_def_load_error_quark ()
typedef enum  {
	CUSTOM_COMPONENT_DEF_LOAD_ERROR_NOT_CUSTOM,
	CUSTOM_COMPONENT_DEF_LOAD_ERROR_MISSING_DEPENDENCY,
	CUSTOM_COMPONENT_DEF_LOAD_ERROR_NAME_CONFLICT,
	CUSTOM_COMPONENT_DEF_LOAD_ERROR_INVALID
} CustomComponentDefLoadError;
#define CUSTOM_COMPONENT_DEF_LOAD_ERROR custom_component_def_load_error_quark ()
typedef enum  {
	PLUGIN_COMPONENT_DEF_LOAD_ERROR_NOT_PLUGIN,
	PLUGIN_COMPONENT_DEF_LOAD_ERROR_INIT_ERROR,
	PLUGIN_COMPONENT_DEF_LOAD_ERROR_LIBRARY_NOT_ACCESSIBLE,
	PLUGIN_COMPONENT_DEF_LOAD_ERROR_LIBRARY_NOT_COMPATIBLE,
	PLUGIN_COMPONENT_DEF_LOAD_ERROR_NAME_CONFLICT,
	PLUGIN_COMPONENT_DEF_LOAD_ERROR_INVALID
} PluginComponentDefLoadError;
#define PLUGIN_COMPONENT_DEF_LOAD_ERROR plugin_component_def_load_error_quark ()
struct _ComponentInst {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ComponentInstPrivate * priv;
	ComponentDef* componentDef;
	gint myID;
	gint xPosition;
	gint yPosition;
	Direction direction;
	gboolean flipped;
	gint rightBound;
	gint downBound;
	gint leftBound;
	gint upBound;
	PropertySet* configuration;
	gboolean selected;
	gboolean errorMark;
	PinInst** pinInsts;
	gint pinInsts_length1;
};

struct _ComponentInstClass {
	GTypeClass parent_class;
	void (*finalize) (ComponentInst *self);
};

struct _PinInst {
	GTypeInstance parent_instance;
	volatile int ref_count;
	PinInstPrivate * priv;
	gint* x;
	gint x_length1;
	gint* y;
	gint y_length1;
	gint* xConnect;
	gint xConnect_length1;
	gint* yConnect;
	gint yConnect_length1;
	gint xLabel;
	gint yLabel;
	WireInst** wireInsts;
	gint wireInsts_length1;
	gboolean* invert;
	gint invert_length1;
	PinDef* pinDef;
	gint arraySize;
	gint xMin;
	gint xMax;
	gint yMin;
	gint yMax;
	gboolean show;
};

struct _PinInstClass {
	GTypeClass parent_class;
	void (*finalize) (PinInst *self);
};


static gpointer reader_component_def_parent_class = NULL;

gpointer component_def_ref (gpointer instance);
void component_def_unref (gpointer instance);
GParamSpec* param_spec_component_def (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_component_def (GValue* value, gpointer v_object);
void value_take_component_def (GValue* value, gpointer v_object);
gpointer value_get_component_def (const GValue* value);
GType component_def_get_type (void) G_GNUC_CONST;
GType direction_get_type (void) G_GNUC_CONST;
gpointer component_inst_ref (gpointer instance);
void component_inst_unref (gpointer instance);
GParamSpec* param_spec_component_inst (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_component_inst (GValue* value, gpointer v_object);
void value_take_component_inst (GValue* value, gpointer v_object);
gpointer value_get_component_inst (const GValue* value);
GType component_inst_get_type (void) G_GNUC_CONST;
GType custom_component_def_get_type (void) G_GNUC_CONST;
gpointer property_item_ref (gpointer instance);
void property_item_unref (gpointer instance);
GParamSpec* param_spec_property_item (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_property_item (GValue* value, gpointer v_object);
void value_take_property_item (GValue* value, gpointer v_object);
gpointer value_get_property_item (const GValue* value);
GType property_item_get_type (void) G_GNUC_CONST;
GType property_set_get_type (void) G_GNUC_CONST;
gpointer compiled_circuit_ref (gpointer instance);
void compiled_circuit_unref (gpointer instance);
GParamSpec* param_spec_compiled_circuit (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_compiled_circuit (GValue* value, gpointer v_object);
void value_take_compiled_circuit (GValue* value, gpointer v_object);
gpointer value_get_compiled_circuit (const GValue* value);
GType compiled_circuit_get_type (void) G_GNUC_CONST;
gpointer connection_ref (gpointer instance);
void connection_unref (gpointer instance);
GParamSpec* param_spec_connection (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_connection (GValue* value, gpointer v_object);
void value_take_connection (GValue* value, gpointer v_object);
gpointer value_get_connection (const GValue* value);
GType connection_get_type (void) G_GNUC_CONST;
gpointer circuit_information_ref (gpointer instance);
void circuit_information_unref (gpointer instance);
GParamSpec* param_spec_circuit_information (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_circuit_information (GValue* value, gpointer v_object);
void value_take_circuit_information (GValue* value, gpointer v_object);
gpointer value_get_circuit_information (const GValue* value);
GType circuit_information_get_type (void) G_GNUC_CONST;
gpointer graphic_ref (gpointer instance);
void graphic_unref (gpointer instance);
GParamSpec* param_spec_graphic (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_graphic (GValue* value, gpointer v_object);
void value_take_graphic (GValue* value, gpointer v_object);
gpointer value_get_graphic (const GValue* value);
GType graphic_get_type (void) G_GNUC_CONST;
gpointer pin_def_ref (gpointer instance);
void pin_def_unref (gpointer instance);
GParamSpec* param_spec_pin_def (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_pin_def (GValue* value, gpointer v_object);
void value_take_pin_def (GValue* value, gpointer v_object);
gpointer value_get_pin_def (const GValue* value);
GType pin_def_get_type (void) G_GNUC_CONST;
GType reader_component_def_get_type (void) G_GNUC_CONST;
enum  {
	READER_COMPONENT_DEF_DUMMY_PROPERTY
};
#define READER_COMPONENT_DEF_infoFilename PACKAGE_DATADIR "components/info/reader.xml"
GQuark component_def_load_error_quark (void);
ReaderComponentDef* reader_component_def_new (GError** error);
ReaderComponentDef* reader_component_def_construct (GType object_type, GError** error);
ComponentDef* component_def_construct (GType object_type);
GQuark custom_component_def_load_error_quark (void);
GQuark plugin_component_def_load_error_quark (void);
void component_def_load_from_file (ComponentDef* self, const gchar* infoFilename, GError** error);
static void reader_component_def_real_compile_component (ComponentDef* base, CompiledCircuit* compiledCircuit, ComponentInst* componentInst, Connection** connections, int connections_length1, ComponentInst** ancestry, int ancestry_length1);
Connection* connection_new_fake (void);
Connection* connection_construct_fake (GType object_type);
gpointer wire_inst_ref (gpointer instance);
void wire_inst_unref (gpointer instance);
GParamSpec* param_spec_wire_inst (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_wire_inst (GValue* value, gpointer v_object);
void value_take_wire_inst (GValue* value, gpointer v_object);
gpointer value_get_wire_inst (const GValue* value);
GType wire_inst_get_type (void) G_GNUC_CONST;
WireInst* connection_get_wireInst (Connection* self);
gpointer pin_inst_ref (gpointer instance);
void pin_inst_unref (gpointer instance);
GParamSpec* param_spec_pin_inst (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_pin_inst (GValue* value, gpointer v_object);
void value_take_pin_inst (GValue* value, gpointer v_object);
gpointer value_get_pin_inst (const GValue* value);
GType pin_inst_get_type (void) G_GNUC_CONST;
ReaderComponentState* reader_component_state_new (Connection* inputWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst);
ReaderComponentState* reader_component_state_construct (GType object_type, Connection* inputWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst);
gpointer component_state_ref (gpointer instance);
void component_state_unref (gpointer instance);
GParamSpec* param_spec_component_state (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_component_state (GValue* value, gpointer v_object);
void value_take_component_state (GValue* value, gpointer v_object);
gpointer value_get_component_state (const GValue* value);
GType component_state_get_type (void) G_GNUC_CONST;
GType reader_component_state_get_type (void) G_GNUC_CONST;
void compiled_circuit_add_component (CompiledCircuit* self, ComponentState* componentState);


ReaderComponentDef* reader_component_def_construct (GType object_type, GError** error) {
	ReaderComponentDef* self = NULL;
	GError * _inner_error_ = NULL;
	self = (ReaderComponentDef*) component_def_construct (object_type);
	{
		component_def_load_from_file ((ComponentDef*) self, READER_COMPONENT_DEF_infoFilename, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch40_g_error;
		}
	}
	goto __finally40;
	__catch40_g_error:
	{
		FILE* _tmp0_;
		GError* _tmp1_;
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		_tmp0_ = stdout;
		fprintf (_tmp0_, "Failed to load built in component \"%s\"\n", READER_COMPONENT_DEF_infoFilename);
		_tmp1_ = g_error_new_literal (COMPONENT_DEF_LOAD_ERROR, COMPONENT_DEF_LOAD_ERROR_LOAD, "Failed to load \"" READER_COMPONENT_DEF_infoFilename "\"\n");
		_inner_error_ = _tmp1_;
		goto __finally40;
	}
	__finally40:
	if (_inner_error_ != NULL) {
		if (_inner_error_->domain == COMPONENT_DEF_LOAD_ERROR) {
			g_propagate_error (error, _inner_error_);
			_component_def_unref0 (self);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	return self;
}


ReaderComponentDef* reader_component_def_new (GError** error) {
	return reader_component_def_construct (TYPE_READER_COMPONENT_DEF, error);
}


static gpointer _connection_ref0 (gpointer self) {
	return self ? connection_ref (self) : NULL;
}


static void reader_component_def_real_compile_component (ComponentDef* base, CompiledCircuit* compiledCircuit, ComponentInst* componentInst, Connection** connections, int connections_length1, ComponentInst** ancestry, int ancestry_length1) {
	ReaderComponentDef * self;
	Connection* _tmp0_;
	Connection* inputWire;
	Connection** _tmp1_;
	gint _tmp1__length1;
	Connection* _tmp13_;
	ComponentInst** _tmp14_;
	gint _tmp14__length1;
	ComponentInst* _tmp15_;
	ReaderComponentState* _tmp16_;
	ComponentState* componentState;
	CompiledCircuit* _tmp17_;
	self = (ReaderComponentDef*) base;
	g_return_if_fail (compiledCircuit != NULL);
	_tmp0_ = connection_new_fake ();
	inputWire = _tmp0_;
	_tmp1_ = connections;
	_tmp1__length1 = connections_length1;
	{
		Connection** connection_collection = NULL;
		gint connection_collection_length1 = 0;
		gint _connection_collection_size_ = 0;
		gint connection_it = 0;
		connection_collection = _tmp1_;
		connection_collection_length1 = _tmp1__length1;
		for (connection_it = 0; connection_it < _tmp1__length1; connection_it = connection_it + 1) {
			Connection* _tmp2_;
			Connection* connection = NULL;
			_tmp2_ = _connection_ref0 (connection_collection[connection_it]);
			connection = _tmp2_;
			{
				Connection* _tmp3_;
				WireInst* _tmp4_;
				WireInst* _tmp5_;
				ComponentInst* _tmp6_;
				PinInst** _tmp7_;
				gint _tmp7__length1;
				PinInst* _tmp8_;
				WireInst** _tmp9_;
				gint _tmp9__length1;
				WireInst* _tmp10_;
				_tmp3_ = connection;
				_tmp4_ = connection_get_wireInst (_tmp3_);
				_tmp5_ = _tmp4_;
				_tmp6_ = componentInst;
				_tmp7_ = _tmp6_->pinInsts;
				_tmp7__length1 = _tmp6_->pinInsts_length1;
				_tmp8_ = _tmp7_[0];
				_tmp9_ = _tmp8_->wireInsts;
				_tmp9__length1 = _tmp8_->wireInsts_length1;
				_tmp10_ = _tmp9_[0];
				if (_tmp5_ == _tmp10_) {
					Connection* _tmp11_;
					Connection* _tmp12_;
					_tmp11_ = connection;
					_tmp12_ = _connection_ref0 (_tmp11_);
					_connection_unref0 (inputWire);
					inputWire = _tmp12_;
				}
				_connection_unref0 (connection);
			}
		}
	}
	_tmp13_ = inputWire;
	_tmp14_ = ancestry;
	_tmp14__length1 = ancestry_length1;
	_tmp15_ = componentInst;
	_tmp16_ = reader_component_state_new (_tmp13_, _tmp14_, _tmp14__length1, _tmp15_);
	componentState = (ComponentState*) _tmp16_;
	_tmp17_ = compiledCircuit;
	compiled_circuit_add_component (_tmp17_, componentState);
	_component_state_unref0 (componentState);
	_connection_unref0 (inputWire);
}


static void reader_component_def_class_init (ReaderComponentDefClass * klass) {
	reader_component_def_parent_class = g_type_class_peek_parent (klass);
	COMPONENT_DEF_CLASS (klass)->compile_component = reader_component_def_real_compile_component;
}


static void reader_component_def_instance_init (ReaderComponentDef * self) {
}


GType reader_component_def_get_type (void) {
	static volatile gsize reader_component_def_type_id__volatile = 0;
	if (g_once_init_enter (&reader_component_def_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ReaderComponentDefClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) reader_component_def_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ReaderComponentDef), 0, (GInstanceInitFunc) reader_component_def_instance_init, NULL };
		GType reader_component_def_type_id;
		reader_component_def_type_id = g_type_register_static (TYPE_COMPONENT_DEF, "ReaderComponentDef", &g_define_type_info, 0);
		g_once_init_leave (&reader_component_def_type_id__volatile, reader_component_def_type_id);
	}
	return reader_component_def_type_id__volatile;
}



