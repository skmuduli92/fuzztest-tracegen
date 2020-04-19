#include "tracerecord.h"

#include <string>
#include "probmodel.h"
#include "tracegen.h"

const int TraceGenerator::DEBUG_REG_ADDR = 0xEFFC;
const int TraceGenerator::DEBUG_REG_DATA = 0xEFFE;
const int TraceGenerator::MAX_TRACES = 100;
uint32_t TraceGenerator::trid = 0;

void TraceGenerator::tracegen_sha(std::shared_ptr<Voc8051_tb> top, std::shared_ptr<TraceGen> tg) {

  tg->recordIntSignal(
      "sha_reg_len", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_len);

  tg->recordIntSignal(
      "byte_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter);

  tg->recordIntSignal(
      "byte_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter_next);

  tg->recordIntSignal(
      "sha_reg_state", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_state);

  tg->recordIntSignal(
      "sha_state_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_state_next);

  tg->recordIntSignal(
      "byte_counter_next_rw", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__byte_counter_next_rw);

  tg->recordIntSignal(
      "ready_flag", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha1_core_i__DOT__ready_flag);

  tg->recordIntSignal(
      "reg_bytes_read", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__reg_bytes_read);


  tg->recordIntSignal(
      "bytes_read_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__bytes_read_next);

  tg->recordIntSignal(
      "block_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__block_counter);

  tg->recordIntSignal(
      "block_counter_next", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__block_counter_next);

  tg->recordIntSignal(
      "sha_reg_rd_addr", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_rd_addr);

  tg->recordIntSignal(
      "sha_reg_wr_addr", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_reg_wr_addr);


    tg->recordIntSignal(
        "sha_more_blocks", trid, sc_time_stamp(),
        (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_more_blocks);

    tg->recordIntSignal(
        "sha_core_init", trid, sc_time_stamp(),
        (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_init);

    tg->recordIntSignal(
        "sha_core_next", trid, sc_time_stamp(),
        (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_next);

    tg->recordIntSignal(
        "sha_core_ready_r", trid, sc_time_stamp(),
        (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__sha_top_i__DOT__sha_core_ready_r);

    tg->recordIntSignal(
        "good_value", trid, sc_time_stamp(),
        (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff[DEBUG_REG_DATA]);

}

void TraceGenerator::tracegen_aes(std::shared_ptr<Voc8051_tb> top,
                                  std::shared_ptr<TraceGen> tg) {

  // substracting 20 for reset time

  tg->recordIntSignal("ack_aes", trid, sc_time_stamp(),
                      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__ack_aes);

  tg->recordIntSignal("aes_xram_ack", trid, sc_time_stamp(),
                      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_xram_ack);

  tg->recordIntSignal(
      "aes_reg_state", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_state);

  tg->recordIntSignal(
      "aes_reg_state_next", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_state_next);

  tg->recordIntSignal(
      "aes_byte_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__byte_counter);

  tg->recordIntSignal(
      "aes_reg_oplen: ", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen);

  tg->recordIntSignal(
      "aes_data_out_mux", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_ctr_i__DOT__data_out_mux);

  tg->recordIntSignal(
      "good_value", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__oc8051_xram_i__DOT__buff
          [DEBUG_REG_DATA]);

  tg->recordIntSignal(
      "aes_reg_oplen", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__aes_reg_oplen);

  tg->recordIntSignal(
      "operated_bytes_count", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__operated_bytes_count);

  tg->recordIntSignal(
      "operated_bytes_count_next", trid, sc_time_stamp(),
      (uint32_t)top
          ->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__operated_bytes_count_next);

  tg->recordIntSignal(
      "block_counter", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__block_counter);

  tg->recordIntSignal(
      "block_counter_next", trid, sc_time_stamp(),
      (uint32_t)
          top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__block_counter_next);

  tg->recordIntSignal(
      "aes_reg_start", trid, sc_time_stamp(),
      (uint32_t)top->oc8051_tb__DOT__oc8051_xiommu1__DOT__aes_top_i__DOT__start_op);
}
