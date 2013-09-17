/* state-tristate.c generated by valac 0.20.1, the Vala compiler
 * generated from state-tristate.vala, do not modify */

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
 *   Filename: componentstate/state-tristate.vala
 *   
 *   Copyright Ashley Newson 2013
 */

#include <glib.h>
#include <glib-object.h>
#include <cairo.h>


#define TYPE_COMPONENT_STATE (component_state_get_type ())
#define COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPONENT_STATE, ComponentState))
#define COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPONENT_STATE, ComponentStateClass))
#define IS_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPONENT_STATE))
#define IS_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPONENT_STATE))
#define COMPONENT_STATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPONENT_STATE, ComponentStateClass))

typedef struct _ComponentState ComponentState;
typedef struct _ComponentStateClass ComponentStateClass;
typedef struct _ComponentStatePrivate ComponentStatePrivate;

#define TYPE_COMPILED_CIRCUIT (compiled_circuit_get_type ())
#define COMPILED_CIRCUIT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPILED_CIRCUIT, CompiledCircuit))
#define COMPILED_CIRCUIT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPILED_CIRCUIT, CompiledCircuitClass))
#define IS_COMPILED_CIRCUIT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPILED_CIRCUIT))
#define IS_COMPILED_CIRCUIT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPILED_CIRCUIT))
#define COMPILED_CIRCUIT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPILED_CIRCUIT, CompiledCircuitClass))

typedef struct _CompiledCircuit CompiledCircuit;
typedef struct _CompiledCircuitClass CompiledCircuitClass;

#define TYPE_COMPONENT_INST (component_inst_get_type ())
#define COMPONENT_INST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPONENT_INST, ComponentInst))
#define COMPONENT_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPONENT_INST, ComponentInstClass))
#define IS_COMPONENT_INST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPONENT_INST))
#define IS_COMPONENT_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPONENT_INST))
#define COMPONENT_INST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPONENT_INST, ComponentInstClass))

typedef struct _ComponentInst ComponentInst;
typedef struct _ComponentInstClass ComponentInstClass;

#define TYPE_TRISTATE_COMPONENT_STATE (tristate_component_state_get_type ())
#define TRISTATE_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRISTATE_COMPONENT_STATE, TristateComponentState))
#define TRISTATE_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRISTATE_COMPONENT_STATE, TristateComponentStateClass))
#define IS_TRISTATE_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRISTATE_COMPONENT_STATE))
#define IS_TRISTATE_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRISTATE_COMPONENT_STATE))
#define TRISTATE_COMPONENT_STATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRISTATE_COMPONENT_STATE, TristateComponentStateClass))

typedef struct _TristateComponentState TristateComponentState;
typedef struct _TristateComponentStateClass TristateComponentStateClass;
typedef struct _TristateComponentStatePrivate TristateComponentStatePrivate;

#define TYPE_CONNECTION (connection_get_type ())
#define CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CONNECTION, Connection))
#define CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CONNECTION, ConnectionClass))
#define IS_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CONNECTION))
#define IS_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CONNECTION))
#define CONNECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CONNECTION, ConnectionClass))

typedef struct _Connection Connection;
typedef struct _ConnectionClass ConnectionClass;
#define _connection_unref0(var) ((var == NULL) ? NULL : (var = (connection_unref (var), NULL)))
#define _component_inst_unref0(var) ((var == NULL) ? NULL : (var = (component_inst_unref (var), NULL)))

struct _ComponentState {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ComponentStatePrivate * priv;
	CompiledCircuit* compiledCircuit;
	ComponentInst** ancestry;
	gint ancestry_length1;
	ComponentInst* componentInst;
	gint renderQueueID;
	gint processQueueID;
	gboolean display;
};

struct _ComponentStateClass {
	GTypeClass parent_class;
	void (*finalize) (ComponentState *self);
	void (*update) (ComponentState* self);
	void (*click) (ComponentState* self);
	void (*render) (ComponentState* self, cairo_t* context);
	gboolean (*get_alwaysUpdate) (ComponentState* self);
};

struct _TristateComponentState {
	ComponentState parent_instance;
	TristateComponentStatePrivate * priv;
};

struct _TristateComponentStateClass {
	ComponentStateClass parent_class;
};

struct _TristateComponentStatePrivate {
	Connection* inputWire;
	Connection* controlWire;
	Connection* outputWire;
};


static gpointer tristate_component_state_parent_class = NULL;

gpointer component_state_ref (gpointer instance);
void component_state_unref (gpointer instance);
GParamSpec* param_spec_component_state (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_component_state (GValue* value, gpointer v_object);
void value_take_component_state (GValue* value, gpointer v_object);
gpointer value_get_component_state (const GValue* value);
GType component_state_get_type (void) G_GNUC_CONST;
gpointer compiled_circuit_ref (gpointer instance);
void compiled_circuit_unref (gpointer instance);
GParamSpec* param_spec_compiled_circuit (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_compiled_circuit (GValue* value, gpointer v_object);
void value_take_compiled_circuit (GValue* value, gpointer v_object);
gpointer value_get_compiled_circuit (const GValue* value);
GType compiled_circuit_get_type (void) G_GNUC_CONST;
gpointer component_inst_ref (gpointer instance);
void component_inst_unref (gpointer instance);
GParamSpec* param_spec_component_inst (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_component_inst (GValue* value, gpointer v_object);
void value_take_component_inst (GValue* value, gpointer v_object);
gpointer value_get_component_inst (const GValue* value);
GType component_inst_get_type (void) G_GNUC_CONST;
GType tristate_component_state_get_type (void) G_GNUC_CONST;
gpointer connection_ref (gpointer instance);
void connection_unref (gpointer instance);
GParamSpec* param_spec_connection (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_connection (GValue* value, gpointer v_object);
void value_take_connection (GValue* value, gpointer v_object);
gpointer value_get_connection (const GValue* value);
GType connection_get_type (void) G_GNUC_CONST;
#define TRISTATE_COMPONENT_STATE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_TRISTATE_COMPONENT_STATE, TristateComponentStatePrivate))
enum  {
	TRISTATE_COMPONENT_STATE_DUMMY_PROPERTY
};
TristateComponentState* tristate_component_state_new (Connection* inputWire, Connection* controlWire, Connection* outputWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst);
TristateComponentState* tristate_component_state_construct (GType object_type, Connection* inputWire, Connection* controlWire, Connection* outputWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst);
ComponentState* component_state_construct (GType object_type);
void connection_set_affects (Connection* self, ComponentState* componentState);
static ComponentInst** _vala_array_dup37 (ComponentInst** self, int length);
static void tristate_component_state_real_update (ComponentState* base);
gboolean connection_get_signalState (Connection* self);
void connection_set_signalState (Connection* self, gboolean value);
void connection_disable_signal (Connection* self);
static void tristate_component_state_finalize (ComponentState* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _connection_ref0 (gpointer self) {
	return self ? connection_ref (self) : NULL;
}


static gpointer _component_inst_ref0 (gpointer self) {
	return self ? component_inst_ref (self) : NULL;
}


static ComponentInst** _vala_array_dup37 (ComponentInst** self, int length) {
	ComponentInst** result;
	int i;
	result = g_new0 (ComponentInst*, length + 1);
	for (i = 0; i < length; i++) {
		ComponentInst* _tmp0_;
		_tmp0_ = _component_inst_ref0 (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


TristateComponentState* tristate_component_state_construct (GType object_type, Connection* inputWire, Connection* controlWire, Connection* outputWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst) {
	TristateComponentState* self = NULL;
	Connection* _tmp0_;
	Connection* _tmp1_;
	Connection* _tmp2_;
	Connection* _tmp3_;
	Connection* _tmp4_;
	Connection* _tmp5_;
	Connection* _tmp6_;
	Connection* _tmp7_;
	ComponentInst** _tmp8_;
	gint _tmp8__length1;
	ComponentInst** _tmp9_;
	gint _tmp9__length1;
	ComponentInst* _tmp10_;
	ComponentInst* _tmp11_;
	g_return_val_if_fail (inputWire != NULL, NULL);
	g_return_val_if_fail (controlWire != NULL, NULL);
	g_return_val_if_fail (outputWire != NULL, NULL);
	g_return_val_if_fail (componentInst != NULL, NULL);
	self = (TristateComponentState*) component_state_construct (object_type);
	_tmp0_ = inputWire;
	_tmp1_ = _connection_ref0 (_tmp0_);
	_connection_unref0 (self->priv->inputWire);
	self->priv->inputWire = _tmp1_;
	_tmp2_ = inputWire;
	connection_set_affects (_tmp2_, (ComponentState*) self);
	_tmp3_ = controlWire;
	_tmp4_ = _connection_ref0 (_tmp3_);
	_connection_unref0 (self->priv->controlWire);
	self->priv->controlWire = _tmp4_;
	_tmp5_ = controlWire;
	connection_set_affects (_tmp5_, (ComponentState*) self);
	_tmp6_ = outputWire;
	_tmp7_ = _connection_ref0 (_tmp6_);
	_connection_unref0 (self->priv->outputWire);
	self->priv->outputWire = _tmp7_;
	_tmp8_ = ancestry;
	_tmp8__length1 = ancestry_length1;
	_tmp9_ = (_tmp8_ != NULL) ? _vala_array_dup37 (_tmp8_, _tmp8__length1) : ((gpointer) _tmp8_);
	_tmp9__length1 = _tmp8__length1;
	((ComponentState*) self)->ancestry = (_vala_array_free (((ComponentState*) self)->ancestry, ((ComponentState*) self)->ancestry_length1, (GDestroyNotify) component_inst_unref), NULL);
	((ComponentState*) self)->ancestry = _tmp9_;
	((ComponentState*) self)->ancestry_length1 = _tmp9__length1;
	_tmp10_ = componentInst;
	_tmp11_ = _component_inst_ref0 (_tmp10_);
	_component_inst_unref0 (((ComponentState*) self)->componentInst);
	((ComponentState*) self)->componentInst = _tmp11_;
	return self;
}


TristateComponentState* tristate_component_state_new (Connection* inputWire, Connection* controlWire, Connection* outputWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst) {
	return tristate_component_state_construct (TYPE_TRISTATE_COMPONENT_STATE, inputWire, controlWire, outputWire, ancestry, ancestry_length1, componentInst);
}


static void tristate_component_state_real_update (ComponentState* base) {
	TristateComponentState * self;
	gboolean output = FALSE;
	Connection* _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	self = (TristateComponentState*) base;
	_tmp0_ = self->priv->controlWire;
	_tmp1_ = connection_get_signalState (_tmp0_);
	_tmp2_ = _tmp1_;
	if (_tmp2_) {
		Connection* _tmp3_;
		gboolean _tmp4_;
		gboolean _tmp5_;
		Connection* _tmp6_;
		gboolean _tmp7_;
		_tmp3_ = self->priv->inputWire;
		_tmp4_ = connection_get_signalState (_tmp3_);
		_tmp5_ = _tmp4_;
		output = _tmp5_;
		_tmp6_ = self->priv->outputWire;
		_tmp7_ = output;
		connection_set_signalState (_tmp6_, _tmp7_);
	} else {
		Connection* _tmp8_;
		_tmp8_ = self->priv->outputWire;
		connection_disable_signal (_tmp8_);
	}
}


static void tristate_component_state_class_init (TristateComponentStateClass * klass) {
	tristate_component_state_parent_class = g_type_class_peek_parent (klass);
	COMPONENT_STATE_CLASS (klass)->finalize = tristate_component_state_finalize;
	g_type_class_add_private (klass, sizeof (TristateComponentStatePrivate));
	COMPONENT_STATE_CLASS (klass)->update = tristate_component_state_real_update;
}


static void tristate_component_state_instance_init (TristateComponentState * self) {
	self->priv = TRISTATE_COMPONENT_STATE_GET_PRIVATE (self);
}


static void tristate_component_state_finalize (ComponentState* obj) {
	TristateComponentState * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_TRISTATE_COMPONENT_STATE, TristateComponentState);
	_connection_unref0 (self->priv->inputWire);
	_connection_unref0 (self->priv->controlWire);
	_connection_unref0 (self->priv->outputWire);
	COMPONENT_STATE_CLASS (tristate_component_state_parent_class)->finalize (obj);
}


GType tristate_component_state_get_type (void) {
	static volatile gsize tristate_component_state_type_id__volatile = 0;
	if (g_once_init_enter (&tristate_component_state_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (TristateComponentStateClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) tristate_component_state_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (TristateComponentState), 0, (GInstanceInitFunc) tristate_component_state_instance_init, NULL };
		GType tristate_component_state_type_id;
		tristate_component_state_type_id = g_type_register_static (TYPE_COMPONENT_STATE, "TristateComponentState", &g_define_type_info, 0);
		g_once_init_leave (&tristate_component_state_type_id__volatile, tristate_component_state_type_id);
	}
	return tristate_component_state_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



