
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Transaction_Manager
 *
 * A transaction acts on a single database connection. If you have multiple class-specific
 * databases, the transaction will not protect interaction among them
 *
  *
 *
 */

/**
 * Checks whether manager has an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction_Manager, has){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "has", 0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, t1, t0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction_Manager::has (Method) File=/Transaction/Manager Line=66");
}

/**
 * Returns a new Phalcon_Transaction or an already created once
 *
 * @param boolean $autoBegin
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, get){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_BOOL(v0, 1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "get", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::get (If) File=/Transaction/Manager Line=67");
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Transaction_Manager::get (Block) File=/Transaction/Manager Line=67");
		phalcon_step_over("Phalcon_Transaction_Manager::get (FunctionCall) File=/Transaction/Manager Line=68");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		add_next_index_string(a0, "Phalcon_Transaction_Manager", 1);
		add_next_index_string(a0, "rollbackPendent", 1);
		p0[0] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("register_shutdown_function", 1, p0);
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=/Transaction/Manager Line=69");
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_BOOL(t1, 1);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_initialized", sizeof("_initialized")-1, t1 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=/Transaction/Manager Line=71");
	t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t2);
	phalcon_debug_assign("$number", t2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Transaction_Manager::get (If) File=/Transaction/Manager Line=72");
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Transaction_Manager::get (Block) File=/Transaction/Manager Line=72");
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=/Transaction/Manager Line=73");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_transaction_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		PHALCON_CPY_WRT(v2, i0);
		phalcon_debug_assign("$transaction", i0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (MethodCall) File=/Transaction/Manager Line=74");
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "settransactionmanager" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], "Phalcon_Transaction_Manager", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "settransactionmanager", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (MethodCall) File=/Transaction/Manager Line=75");
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "setdependencypointer" TSRMLS_CC);
		t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(t3);
		p3[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setdependencypointer", 1, p3, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (AssignOp) File=/Transaction/Manager Line=76");
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_LONG(t5, 2048);
		PHALCON_ALLOC_ZVAL(r0);
		add_function(r0, t4, t5 TSRMLS_CC);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_dependencyPointer", sizeof("_dependencyPointer")-1, r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=/Transaction/Manager Line=77");
		t6 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (Z_TYPE_P(t6) != IS_ARRAY) {
			convert_to_array(t6);
		}
		phalcon_array_append(t6, v2 TSRMLS_CC);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, t6 TSRMLS_CC);
		
		phalcon_step_over("Phalcon_Transaction_Manager::get (PostIncDecOp) File=/Transaction/Manager Line=78");
		t7 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_SEPARATE(t7);
		increment_function(t7);
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t7 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Transaction_Manager::get (Block) File=/Transaction/Manager Line=79");
		phalcon_step_over("Phalcon_Transaction_Manager::get (Assignment) File=/Transaction/Manager Line=80");
		t8 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t10);
		ZVAL_LONG(t10, 1);
		PHALCON_ALLOC_ZVAL(r1);
		sub_function(r1, v1, t10 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t9);
		phalcon_array_fetch(t9, t8, r1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, t9);
		phalcon_debug_assign("$transaction", t9 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::get (MethodCall) File=/Transaction/Manager Line=81");
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "setisnewtransaction" TSRMLS_CC);
		PHALCON_PARAM_BOOL(p4[0], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setisnewtransaction", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction_Manager::get (Method) File=/Transaction/Manager Line=90");
}

/**
 * Rollbacks active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollbackPendent){


	phalcon_step_into_entry("Phalcon_Transaction_Manager", "rollbackPendent", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::rollbackPendent (StaticMethodCall) File=/Transaction/Manager Line=91");
	PHALCON_CALL_SELF_NORETURN(this_ptr, "rollback");
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::rollbackPendent (Method) File=/Transaction/Manager Line=98");
}

/**
 * Commmits active transactions whithin the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, commit){

	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "commit", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::commit (Foreach) File=/Transaction/Manager Line=99");
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	FOREACH_V(t0, ac0, fes57, fee57, ah0, hp0, v0)
		phalcon_step_over("Phalcon_Transaction_Manager::commit (Block) File=/Transaction/Manager Line=99");
		phalcon_step_over("Phalcon_Transaction_Manager::commit (Assignment) File=/Transaction/Manager Line=100");
		if (!r0) {
			PHALCON_ALLOC_ZVAL(r0);
		} else {
			if (Z_REFCOUNT_P(r0) > 1) {
				PHALCON_SEPARATE(r0);
			} else {
				FREE_ZVAL(r0);
				PHALCON_ALLOC_ZVAL(r0);
			}
		}
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v0, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r0);
		phalcon_debug_assign("$connection", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::commit (If) File=/Transaction/Manager Line=101");
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1) {
				PHALCON_SEPARATE(r1);
			} else {
				FREE_ZVAL(r1);
				PHALCON_ALLOC_ZVAL(r1);
			}
		}
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v1, "isundertransaction" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, v1, "isundertransaction", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Transaction_Manager::commit (Block) File=/Transaction/Manager Line=101");
			phalcon_step_over("Phalcon_Transaction_Manager::commit (MethodCall) File=/Transaction/Manager Line=102");
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_debug_method_call(v1, "commit" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v1, "commit", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		}
	END_FOREACH(ac0, fes57, fee57, ah0, hp0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::commit (Method) File=/Transaction/Manager Line=113");
}

/**
 * Rollbacks active transactions whithin the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean $collect
 */
PHP_METHOD(Phalcon_Transaction_Manager, rollback){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p4[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "rollback", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::rollback (Foreach) File=/Transaction/Manager Line=114");
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	FOREACH_V(t0, ac0, fes58, fee58, ah0, hp0, v1)
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (Block) File=/Transaction/Manager Line=114");
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (Assignment) File=/Transaction/Manager Line=115");
		if (!r0) {
			PHALCON_ALLOC_ZVAL(r0);
		} else {
			if (Z_REFCOUNT_P(r0) > 1) {
				PHALCON_SEPARATE(r0);
			} else {
				FREE_ZVAL(r0);
				PHALCON_ALLOC_ZVAL(r0);
			}
		}
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v1, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v1, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		phalcon_debug_assign("$connection", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (If) File=/Transaction/Manager Line=116");
		if (!r1) {
			PHALCON_ALLOC_ZVAL(r1);
		} else {
			if (Z_REFCOUNT_P(r1) > 1) {
				PHALCON_SEPARATE(r1);
			} else {
				FREE_ZVAL(r1);
				PHALCON_ALLOC_ZVAL(r1);
			}
		}
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		phalcon_debug_method_call(v2, "isundertransaction" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, v2, "isundertransaction", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (Block) File=/Transaction/Manager Line=116");
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (MethodCall) File=/Transaction/Manager Line=117");
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_debug_method_call(v2, "rollback" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v2, "rollback", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (MethodCall) File=/Transaction/Manager Line=118");
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
			phalcon_debug_method_call(v2, "close" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v2, "close", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Transaction_Manager" TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Transaction_Manager::rollback (If) File=/Transaction/Manager Line=120");
		if (zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (Block) File=/Transaction/Manager Line=120");
			phalcon_step_over("Phalcon_Transaction_Manager::rollback (StaticMethodCall) File=/Transaction/Manager Line=121");
			Z_ADDREF_P(v1);
			p4[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p4);
		}
	END_FOREACH(ac0, fes58, fee58, ah0, hp0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::rollback (Method) File=/Transaction/Manager Line=131");
}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyRollback){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "notifyRollback", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::notifyRollback (StaticMethodCall) File=/Transaction/Manager Line=135");
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::notifyRollback (Method) File=/Transaction/Manager Line=143");
}

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon_Transaction $transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, notifyCommit){

	zval *v0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "notifyCommit", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::notifyCommit (StaticMethodCall) File=/Transaction/Manager Line=147");
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_SELF_PARAMS_NORETURN(this_ptr, "_collecttransaction", 1, p0);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::notifyCommit (Method) File=/Transaction/Manager Line=150");
}

PHP_METHOD(Phalcon_Transaction_Manager, _collectTransaction){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Transaction_Manager", "_collectTransaction", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (If) File=/Transaction/Manager Line=151");
	PHALCON_ALLOC_ZVAL(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=/Transaction/Manager Line=151");
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=/Transaction/Manager Line=152");
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_LONG(v1, 0);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Foreach) File=/Transaction/Manager Line=153");
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		FOREACH_V(t2, ac0, fes59, fee59, ah0, hp0, v2)
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=/Transaction/Manager Line=153");
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (If) File=/Transaction/Manager Line=154");
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1){ 
					PHALCON_SEPARATE(r2);
				}
			}
			is_equal_function(r2, v2, v0 TSRMLS_CC);
			if (zend_is_true(r2)) {
				phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=/Transaction/Manager Line=154");
				phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (PostIncDecOp) File=/Transaction/Manager Line=157");
				t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
				PHALCON_SEPARATE(t3);
				decrement_function(t3);
				zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (PostIncDecOp) File=/Transaction/Manager Line=159");
			PHALCON_SEPARATE(v1);
			increment_function(v1);
			phalcon_debug_vdump("PostIncrementing $number", v1);
		END_FOREACH(ac0, fes59, fee59, ah0, hp0);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=/Transaction/Manager Line=161");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v3, a0);
		phalcon_debug_assign("$transactions", a0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Foreach) File=/Transaction/Manager Line=162");
		t4 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		FOREACH_V(t4, ac1, fes60, fee60, ah1, hp1, v2)
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Block) File=/Transaction/Manager Line=162");
			phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=/Transaction/Manager Line=163");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				PHALCON_SEPARATE(v3);
				phalcon_array_append(v3, copy TSRMLS_CC);
			}
		END_FOREACH(ac1, fes60, fee60, ah1, hp1);
		phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Assignment) File=/Transaction/Manager Line=165");
		zend_update_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, v3 TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::_collectTransaction (Method) File=/Transaction/Manager Line=173");
}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Transaction_Manager, collectTransactions){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "collectTransactions", 0);
	phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (If) File=/Transaction/Manager Line=174");
	PHALCON_ALLOC_ZVAL(r0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Block) File=/Transaction/Manager Line=174");
		phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Assignment) File=/Transaction/Manager Line=175");
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_LONG(v0, 0);
		phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Foreach) File=/Transaction/Manager Line=176");
		t2 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_transactions", sizeof("_transactions")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		FOREACH_V(t2, ac0, fes61, fee61, ah0, hp0, v1)
			phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Block) File=/Transaction/Manager Line=176");
			phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (PostIncDecOp) File=/Transaction/Manager Line=178");
			t3 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_SEPARATE(t3);
			decrement_function(t3);
			zend_update_static_property(phalcon_transaction_manager_class_entry, "_number", sizeof("_number")-1, t3 TSRMLS_CC);
			phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (PostIncDecOp) File=/Transaction/Manager Line=179");
			PHALCON_SEPARATE_PARAM(v0);
			increment_function(v0);
			phalcon_debug_vdump("PostIncrementing $number", v0);
		END_FOREACH(ac0, fes61, fee61, ah0, hp0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Transaction_Manager::collectTransactions (Method) File=/Transaction/Manager Line=190");
}

/**
 * Checks whether manager will inject an automatic transaction to all newly
 * created instances of Phalcon_Model_base
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Transaction_Manager, isAutomatic){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "isAutomatic", 0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_NULL(t1);
	PHALCON_ALLOC_ZVAL(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Transaction_Manager::isAutomatic (Method) File=/Transaction/Manager Line=199");
}

/**
 * Returns automatic transaction for instances of Phalcon_Model_base
 *
 * @return Phalcon_Transaction
 */
PHP_METHOD(Phalcon_Transaction_Manager, getAutomatic){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Transaction_Manager", "getAutomatic", 0);
	t0 = zend_read_static_property(phalcon_transaction_manager_class_entry, "_automaticTransaction", sizeof("_automaticTransaction")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
}

