
#include <string>
#include <vector>
#include "secureboot.h"

const int TraceGenerator::DEBUG_REG_ADDR = 0xEFFC;
const int TraceGenerator::DEBUG_REG_DATA = 0xEFFE;
const int TraceGenerator::MAX_TRACES = 100;
const uint32_t TraceGenerator::RESET_TIME = 20;

void TraceGenerator::addVars(std::vector<std::string> const& intvars) {
  for (std::string const& var : intvars) {
    intvar2id[var] = int_facts.size();
    int_facts.push_back(std::ofstream(genFileName(var)));
  }
}

std::string TraceGenerator::genFileName(std::string const& varname, bool fact) {
  std::string fname = varname + "_";

  if (fact)
    fname += "true.facts";
  else
    fname += "false.facts";

  filenames.push_back(fname);
  return fname;
}

std::string TraceGenerator::genFileName(std::string const& varname) {
  std::string fname = varname + ".facts";
  filenames.push_back(fname);
  return fname;
}

void TraceGenerator::recordSignal(std::string const& sname, uint32_t traceId, uint64_t time,
                                  int64_t value) {

  if (time >= RESET_TIME) {

    if (intvar2id.find(sname) != intvar2id.end())
      int_facts[intvar2id[sname]] << traceId << "\t" << time - 20 << "\t" << value
                                  << std::endl;
  }
}

void TraceGenerator::tracegen_sha(std::shared_ptr<Voc8051_tb> top,
                                  std::shared_ptr<TraceGenerator> tg) {

  recordSignal(
      "sha_reg_len", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_len);

  recordSignal(
      "byte_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter);

  recordSignal(
      "byte_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter_next);

  recordSignal(
      "sha_reg_state", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_state);

  recordSignal(
      "sha_state_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_state_next);

  recordSignal(
      "byte_counter_next_rw", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter_next_rw);

  recordSignal(
      "ready_flag", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha1_core_i__DOT__ready_flag);

  recordSignal(
      "reg_bytes_read", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__reg_bytes_read);

  recordSignal(
      "bytes_read_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__bytes_read_next);

  recordSignal(
      "block_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__block_counter);

  recordSignal(
      "block_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__block_counter_next);

  recordSignal(
      "sha_reg_rd_addr", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_rd_addr);

  recordSignal(
      "sha_reg_wr_addr", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_wr_addr);

  recordSignal(
      "sha_more_blocks", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_more_blocks);

  recordSignal(
      "sha_core_init", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_init);

  recordSignal(
      "sha_core_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_next);

  recordSignal(
      "sha_core_ready_r", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_ready_r);

  recordSignal(
      "good_value", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_DATA]);
}

void TraceGenerator::tracegen_aes(std::shared_ptr<Voc8051_tb> top,
                                  std::shared_ptr<TraceGenerator> tg) {

  // substracting 20 for reset time

  recordSignal("ack_aes", trid, sc_time_stamp(),
               (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__ack_aes);

  recordSignal("aes_xram_ack", trid, sc_time_stamp(),
               (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_xram_ack);

  recordSignal(
      "aes_reg_state", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_state);

  recordSignal(
      "aes_reg_state_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_state_next);

  recordSignal(
      "aes_byte_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__byte_counter);

  recordSignal(
      "aes_reg_oplen: ", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen);

  recordSignal(
      "aes_data_out_mux", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_ctr_i__DOT__data_out_mux);

  recordSignal(
      "good_value", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_DATA]);

  recordSignal(
      "aes_reg_oplen", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen);

  recordSignal(
      "operated_bytes_count", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__operated_bytes_count);

  recordSignal(
      "operated_bytes_count_next", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__operated_bytes_count_next);

  recordSignal(
      "block_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__block_counter);

  recordSignal(
      "block_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__block_counter_next);

  recordSignal("aes_reg_start", trid, sc_time_stamp(),
               (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__start_op);
}

void TraceGenerator::tracegen_page_table(std::shared_ptr<Voc8051_tb> top,
                                         std::shared_ptr<TraceGenerator> tg) {

  const unsigned read_succeed = (0xEFE6);
  const unsigned write_succeed = (0xEFEA);

  std::vector<std::string> signals(
      {"read_succeed",   "write_succeed", "wr_addr",       "rd_addr",      "ack_w",
       "ack_r",          "ia_addr_reg",   "pc_ia_reg",     "ia_reg_next",  "pt_in_wr_range",
       "pt_in_rd_range", "pt_wr_reg_use", "pt_rd_reg_use", "ia_rwn_reg",   "illegal_src",
       "illegal_wr",     "illegal_rd",    "accesser",      "ia_src_next",  "wr_enabled_0",
       "wr_enabled_1",   "wr_enabled_2",  "rd_enabled_0",  "rd_enabled_1", "rd_enabled_2"});

  std::vector<uint32_t> values(
      {top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[read_succeed],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[write_succeed],
       top->oc8051_tb__DOT__oc8051_top_1__DOT__wr_addr,
       top->oc8051_tb__DOT__oc8051_top_1__DOT__rd_addr,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackw,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__ackr,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_addr_reg,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pc_ia_reg,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_reg_next,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_in_wr_range,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_in_rd_range,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_wr_reg_use,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__pt_rd_reg_use,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_rwn_reg,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__illegal_src,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__illegal_wr,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__illegal_rd,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__accesser,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__ia_src_next,
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[0],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[1],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__wr_enabled[2],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[0],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[1],
       top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_page_table_i__DOT__rd_enabled[2]});

  if (signals.size() != values.size()) {
    std::cerr << "SIGNALS AND VALUES VECTOR SIZE MISMATCH" << std::endl;
    exit(1);
  }

  for (size_t xid = 0; xid < signals.size(); ++xid) {
    recordSignal(signals[xid], trid, sc_time_stamp(), values[xid]);
  }
}
