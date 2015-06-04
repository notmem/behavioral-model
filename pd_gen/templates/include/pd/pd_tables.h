#ifndef _P4_PD_TABLES_H_
#define _P4_PD_TABLES_H_

#include "pd/pd_types.h"
#include "pd/pd_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ADD ENTRIES */

//:: for t_name, t in tables.items():
//::   t_type = t.type_
//::   if t_type != TableType.SIMPLE: continue
//::   t_name = get_c_name(t_name)
//::   match_type = t.match_type
//::   has_match_spec = len(t.key) > 0
//::   for a_name, a in t.actions.items():
//::     a_name = get_c_name(a_name)
//::     has_action_spec = len(a.runtime_data) > 0
//::     params = ["p4_pd_sess_hdl_t sess_hdl",
//::               "p4_pd_dev_target_t dev_tgt"]
//::     if has_match_spec:
//::       params += [pd_prefix + t_name + "_match_spec_t *match_spec"]
//::     #endif
//::     if match_type == MatchType.TERNARY:
//::       params += ["int priority"]
//::     #endif
//::     if has_action_spec:
//::       params += [pd_prefix + a_name + "_action_spec_t *action_spec"]
//::     #endif
//::     params += ["p4_pd_entry_hdl_t *entry_hdl"]
//::     param_str = ",\n ".join(params)
//::     name = pd_prefix + t_name + "_table_add_with_" + a_name
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   #endfor
//:: #endfor

//:: for t_name, t in tables.items():
//::   t_type = t.type_
//::   if t_type == TableType.SIMPLE: continue
//::   t_name = get_c_name(t_name)
//::   act_prof_name = get_c_name(t.act_prof)
//::   match_type = t.match_type
//::   has_match_spec = len(t.key) > 0
//::   params = ["p4_pd_sess_hdl_t sess_hdl",
//::             "p4_pd_dev_target_t dev_tgt"]
//::   if has_match_spec:
//::     params += [pd_prefix + t_name + "_match_spec_t *match_spec"]
//::   #endif
//::   if match_type == MatchType.TERNARY:
//::     params += ["int priority"]
//::   #endif
//::
//::   params_indirect = params + ["p4_pd_mbr_hdl_t mbr_hdl", "p4_pd_entry_hdl_t *entry_hdl"]
//::   param_str = ",\n ".join(params_indirect)
//::   name = pd_prefix + t_name + "_add_entry"
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   if t_type != TableType.INDIRECT_WS: continue
//::   params_indirect_ws = params + ["p4_pd_grp_hdl_t grp_hdl", "p4_pd_entry_hdl_t *entry_hdl"]
//::   param_str = ",\n ".join(params_indirect_ws)
//::   name = pd_prefix + t_name + "_add_entry_with_selector"
p4_pd_status_t
${name}
(
 ${param_str}
);

//:: #endfor

/* DELETE ENTRIES */

//:: for t_name, t in tables.items():
//::   t_name = get_c_name(t_name)
//::   name = pd_prefix + t_name + "_table_delete"
p4_pd_status_t
${name}
(
 p4_pd_sess_hdl_t sess_hdl,
 uint8_t dev_id,
 p4_pd_entry_hdl_t entry_hdl
);

//:: #endfor

/* MODIFY ENTRIES */

//:: for t_name, t in tables.items():
//::   t_type = t.type_
//::   if t_type != TableType.SIMPLE: continue
//::   t_name = get_c_name(t_name)
//::   for a_name, a in t.actions.items():
//::     a_name = get_c_name(a_name)
//::     has_action_spec = len(a.runtime_data) > 0
//::     params = ["p4_pd_sess_hdl_t sess_hdl",
//::               "uint8_t dev_id",
//::               "p4_pd_entry_hdl_t entry_hdl"]
//::     if has_action_spec:
//::       params += [pd_prefix + a_name + "_action_spec_t *action_spec"]
//::     #endif
//::     param_str = ",\n ".join(params)
//::     name = pd_prefix + t_name + "_table_modify_with_" + a_name
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   #endfor
//:: #endfor


/* SET DEFAULT_ACTION */

//:: for t_name, t in tables.items():
//::   t_type = t.type_
//::   if t_type != TableType.SIMPLE: continue
//::   t_name = get_c_name(t_name)
//::   for a_name, a in t.actions.items():
//::     a_name = get_c_name(a_name)
//::     has_action_spec = len(a.runtime_data) > 0
//::     params = ["p4_pd_sess_hdl_t sess_hdl",
//::               "p4_pd_dev_target_t dev_tgt"]
//::     if has_action_spec:
//::       params += [pd_prefix + a_name + "_action_spec_t *action_spec"]
//::     #endif
//::     params += ["p4_pd_entry_hdl_t *entry_hdl"]
//::     param_str = ",\n ".join(params)
//::     name = pd_prefix + t_name + "_set_default_action_" + a_name
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   #endfor
//:: #endfor

//:: for t_name, t in tables.items():
//::   t_type = t.type_
//::   if t_type == TableType.SIMPLE: continue
//::   t_name = get_c_name(t_name)
//::   params = ["p4_pd_sess_hdl_t sess_hdl",
//::             "p4_pd_dev_target_t dev_tgt"]
//::
//::   params_indirect = params + ["p4_pd_mbr_hdl_t mbr_hdl", "p4_pd_entry_hdl_t *entry_hdl"]
//::   param_str = ",\n ".join(params_indirect)
//::   name = pd_prefix + t_name + "_set_default_entry"
p4_pd_status_t
${name}
(
 ${param_str}
);
//::   if t_type != TableType.INDIRECT_WS: continue
//::   params_indirect_ws = params + ["p4_pd_grp_hdl_t grp_hdl", "p4_pd_entry_hdl_t *entry_hdl"]
//::   param_str = ",\n ".join(params_indirect_ws)
//::   name = pd_prefix + t_name + "_set_default_entry_with_selector"
p4_pd_status_t
${name}
(
 ${param_str}
);

//:: #endfor

//:: for t_name, t in tables.items():
//::   t_type = t.type_
//::   if t_type == TableType.SIMPLE: continue
//::   t_name = get_c_name(t_name)
//::   act_prof_name = get_c_name(t.act_prof)
//::   match_type = t.match_type
//::   has_match_spec = len(t.key) > 0
//::   for a_name, a in t.actions.items():
//::     a_name = get_c_name(a_name)
//::     has_action_spec = len(a.runtime_data) > 0
//::     params = ["p4_pd_sess_hdl_t sess_hdl",
//::               "p4_pd_dev_target_t dev_tgt"]
//::     if has_action_spec:
//::       params += [pd_prefix + a_name + "_action_spec_t *action_spec"]
//::     #endif
//::     params += ["p4_pd_mbr_hdl_t *mbr_hdl"]
//::     param_str = ",\n ".join(params)
//::     name = pd_prefix + act_prof_name + "_add_member_with_" + a_name
p4_pd_status_t
${name}
(
 ${param_str}
);

//::     params = ["p4_pd_sess_hdl_t sess_hdl",
//::               "uint8_t dev_id",
//::               "p4_pd_mbr_hdl_t mbr_hdl"]
//::     if has_action_spec:
//::       params += [pd_prefix + a_name + "_action_spec_t *action_spec"]
//::     #endif
//::     param_str = ",\n ".join(params)
//::     name = pd_prefix + act_prof_name + "_modify_member_with_" + a_name
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   #endfor
//::
//::   params = ["p4_pd_sess_hdl_t sess_hdl",
//::             "uint8_t dev_id",
//::             "p4_pd_mbr_hdl_t mbr_hdl"]
//::   param_str = ",\n ".join(params)
//::   name = pd_prefix + act_prof_name + "_del_member"
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   if t.type_ != TableType.INDIRECT_WS: continue
//::
//::   params = ["p4_pd_sess_hdl_t sess_hdl",
//::             "p4_pd_dev_target_t dev_tgt",
//::             "uint16_t max_grp_size",
//::             "p4_pd_grp_hdl_t *grp_hdl"]
//::   param_str = ",\n ".join(params)
//::   name = pd_prefix + act_prof_name + "_create_group"
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   params = ["p4_pd_sess_hdl_t sess_hdl",
//::             "uint8_t dev_id",
//::             "p4_pd_grp_hdl_t grp_hdl"]
//::   param_str = ",\n ".join(params)
//::   name = pd_prefix + act_prof_name + "_del_group"
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   params = ["p4_pd_sess_hdl_t sess_hdl",
//::             "uint8_t dev_id",
//::             "p4_pd_mbr_hdl_t mbr_hdl",
//::             "p4_pd_grp_hdl_t grp_hdl"]
//::   param_str = ",\n ".join(params)
//::   name = pd_prefix + act_prof_name + "_add_member_to_group"
p4_pd_status_t
${name}
(
 ${param_str}
);

//::   params = ["p4_pd_sess_hdl_t sess_hdl",
//::             "uint8_t dev_id",
//::             "p4_pd_grp_hdl_t grp_hdl",
//::             "p4_pd_mbr_hdl_t mbr_hdl"]
//::   param_str = ",\n ".join(params)
//::   name = pd_prefix + act_prof_name + "_del_member_from_group"
p4_pd_status_t
${name}
(
 ${param_str}
);

//:: #endfor


/* DIRECT COUNTERS */

//:: for t_name, t in tables.items():
//::   if not t.with_counters: continue
//::   t_name = get_c_name(t_name)
//::   name = pd_prefix + t_name + "_read_counter"
p4_pd_status_t
${name}
(
 p4_pd_sess_hdl_t sess_hdl,
 p4_pd_dev_target_t dev_tgt,
 p4_pd_entry_hdl_t entry_hdl,
 p4_pd_counter_value_t *counter_value
);

//::   name = pd_prefix + t_name + "_reset_counters"
p4_pd_status_t
${name}
(
 p4_pd_sess_hdl_t sess_hdl,
 p4_pd_dev_target_t dev_tgt
);

//:: #endfor

#ifdef __cplusplus
}
#endif

#endif
