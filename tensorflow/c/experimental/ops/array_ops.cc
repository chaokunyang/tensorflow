/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include "tensorflow/c/experimental/ops/array_ops.h"

#include "tensorflow/c/eager/tracing_utils.h"
#include "tensorflow/core/platform/errors.h"

using tensorflow::tracing::MaybeSetOpName;

namespace tensorflow {
namespace ops {

Status Identity(AbstractContext* ctx, AbstractTensorHandle* const input,
                absl::Span<AbstractTensorHandle*> output, const char* name) {
  AbstractOperationPtr identity_op(ctx->CreateOperation());
  TF_RETURN_IF_ERROR(
      identity_op->Reset("Identity", /*raw_device_name=*/nullptr));
  TF_RETURN_IF_ERROR(MaybeSetOpName(identity_op.get(), name));
  TF_RETURN_IF_ERROR(identity_op->AddInput(input));
  int num_retvals = 1;
  return identity_op->Execute(output, &num_retvals);
}

Status IdentityN(AbstractContext* ctx,
                 absl::Span<AbstractTensorHandle* const> input,
                 absl::Span<AbstractTensorHandle*> output, const char* name) {
  AbstractOperationPtr identity_n_op(ctx->CreateOperation());
  TF_RETURN_IF_ERROR(
      identity_n_op->Reset("IdentityN", /*raw_device_name=*/nullptr));
  TF_RETURN_IF_ERROR(MaybeSetOpName(identity_n_op.get(), name));
  TF_RETURN_IF_ERROR(identity_n_op->AddInputList(input));
  int num_retvals = input.size();
  return identity_n_op->Execute(output, &num_retvals);
}

Status ZerosLike(AbstractContext* ctx, AbstractTensorHandle* const x,
                 absl::Span<AbstractTensorHandle*> y, const char* name) {
  AbstractOperationPtr z_op(ctx->CreateOperation());
  TF_RETURN_IF_ERROR(z_op->Reset("ZerosLike", /*raw_device_name=*/nullptr));
  TF_RETURN_IF_ERROR(MaybeSetOpName(z_op.get(), name));
  TF_RETURN_IF_ERROR(z_op->AddInput(x));
  int num_retvals = 1;
  return z_op->Execute(y, &num_retvals);
}

Status Shape(AbstractContext* ctx, AbstractTensorHandle* const input,
             absl::Span<AbstractTensorHandle*> output, const char* name) {
  AbstractOperationPtr shape_op(ctx->CreateOperation());
  TF_RETURN_IF_ERROR(shape_op->Reset("Shape", /*raw_device_name=*/nullptr));
  TF_RETURN_IF_ERROR(MaybeSetOpName(shape_op.get(), name));
  TF_RETURN_IF_ERROR(shape_op->AddInput(input));  // input
  int num_retvals = 1;
  TF_RETURN_IF_ERROR(shape_op->Execute(output, &num_retvals));
  return Status::OK();
}

Status ExpandDims(AbstractContext* ctx, AbstractTensorHandle* const input,
                  AbstractTensorHandle* const dim,
                  absl::Span<AbstractTensorHandle*> output, const char* name) {
  AbstractOperationPtr op(ctx->CreateOperation());
  TF_RETURN_IF_ERROR(op->Reset("ExpandDims", /*raw_device_name=*/nullptr));
  TF_RETURN_IF_ERROR(MaybeSetOpName(op.get(), name));
  TF_RETURN_IF_ERROR(op->AddInput(input));
  TF_RETURN_IF_ERROR(op->AddInput(dim));
  int num_retvals = 1;
  return op->Execute(output, &num_retvals);
}

Status OnesLike(AbstractContext* ctx, AbstractTensorHandle* const x,
                absl::Span<AbstractTensorHandle*> y, const char* name) {
  AbstractOperationPtr op(ctx->CreateOperation());
  TF_RETURN_IF_ERROR(op->Reset("OnesLike", /*raw_device_name=*/nullptr));
  TF_RETURN_IF_ERROR(MaybeSetOpName(op.get(), name));
  TF_RETURN_IF_ERROR(op->AddInput(x));

  int num_retvals = 1;
  return op->Execute(y, &num_retvals);
}

}  // namespace ops
}  // namespace tensorflow
